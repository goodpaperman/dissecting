#include <windows.h>
#include <stdio.h>
#include <string.h>

#define FILEMAX 300  // allow max. 300 files in each directory

typedef struct _DESTFILE
{
    WIN32_FIND_DATA fd;
    BOOL bMatch;
} DESTFILE;

typedef struct _SRCFILE
{
    WIN32_FIND_DATA fd;
    BOOL bIsNew;
} SRCFILE;

void main(int argc, char *argv[])
{
    int i, j, iSrcFiles, iDestFiles;
    HANDLE hFile;
    WIN32_FIND_DATA fd;
    BOOL bRet = TRUE;
    char src[MAX_PATH+1], dest[MAX_PATH+1], destpath[MAX_PATH+1], srcpath[MAX_PATH+1];
    SRCFILE  srcFiles[FILEMAX];
    DESTFILE destFiles[FILEMAX];
    BOOL bFound = FALSE;
    DWORD dwcNameSize = MAX_PATH+1;
    char szBuffer[MAX_PATH+1];
        
    if (argc < 2) 
    {
        printf("jbackup <SrcDir> <DstDir> \n");
        printf("例如 jbackup d: g: \n\n");
                
        printf("将驱动器目录 SrcDir 中的新文件复制到驱动器目录 DstDir \n");
        printf("并将 DstDir 中赘余的文件杀掉。 \n\n");
                
        printf("如果没有指定 DstDir, 默认为 g: \n");
        printf("并将 g: 的驱动器目录设定与 SrcDir 相同。\n\n");
                
        printf("例如 jbackup d: <Enter> \n");
        printf("而当前 d: 是 d:\\u002\\doc \n");
        printf("那么相当于把 d:\\u002\\doc 备份到 g:\\u002\\doc 中, 并杀掉 g:\\u002\\doc 的赘余文件。\n");
        return;
    }
        
    // for (i=0; i< argc; i++)
    //     printf("argv[%d]: %s \n", i, argv[i]);
        
    strcpy(src, argv[1]);
    if (argc == 2) 
    {
        GetCurrentDirectory(dwcNameSize, &szBuffer);
        strcpy(dest, szBuffer);
        // printf("current directory : %s \n", dest);
        dest[0] = 'g';
        strcpy(destpath, dest); // destpath should be something like "g:\u002\doc\".
        strcat(destpath, "\\"); // just prepare for use latter (when updating and deleting).
                
        strcat(dest, "\\*.*");  // dest should be something like "g:\u002\doc\*.*"
    }
    else 
    {
        strcpy(destpath, argv[2]); // destpath should be something like "g:\"
                                 // just prepare for usage latter (when updating and deleting).
        strcpy(dest, argv[2]);
        strcat(dest, "*.*");       // then dest should be something like "g:\*.*"
    }
        
    strcpy(srcpath, src); 
    strcat(src, "*.*");         // src should be something like d:\*.*
    printf("src=%s \n", src);
    printf("dest=%s \n", dest);
    printf("destpath=%s \n", destpath);
        
        
    // prepare srcFiles[]...
    bRet = TRUE;
    iSrcFiles = 0;
    // printf("Directory listing of %s\n", src);
    hFile = FindFirstFile(src, &fd);
    while (hFile != INVALID_HANDLE_VALUE && bRet && iSrcFiles < FILEMAX)
    {
        if (fd.dwFileAttributes == FILE_ATTRIBUTE_ARCHIVE) 
        {
            srcFiles[iSrcFiles].fd = fd;
            srcFiles[iSrcFiles].bIsNew = FALSE;
            // printf("%s\n", srcFiles[iSrcFiles].fd.cFileName);
            iSrcFiles++;
        }
        bRet = FindNextFile(hFile, &fd);
    }
        
        
    // prepare destFiles[]...
    bRet = TRUE;
    iDestFiles = 0;
    // printf("Directory listing of %s\n", dest);
    hFile = FindFirstFile(dest, &fd);
    while (hFile != INVALID_HANDLE_VALUE && bRet && iDestFiles < FILEMAX)
    {
        if (fd.dwFileAttributes == FILE_ATTRIBUTE_ARCHIVE) 
        {
            destFiles[iDestFiles].fd = fd;
            destFiles[iDestFiles].bMatch = FALSE;
            // printf("%s\n", destFiles[iDestFiles].fd.cFileName);
            iDestFiles++;
        }
        bRet = FindNextFile(hFile, &fd);
    }
        
        
    // check for new files and redudant files...
    for (i=0; i<iSrcFiles; i++) 
    {
        bFound = FALSE;
        for (j=0; j<iDestFiles; j++) 
        {
            if (!(destFiles[j].bMatch))  
            {
                if (strcmpi(destFiles[j].fd.cFileName, srcFiles[i].fd.cFileName) == 0) 
                {
                    // find same files in dest directory
                    destFiles[j].bMatch = TRUE;
                    bFound = TRUE;
                                                
                    if (CompareFileTime(&destFiles[j].fd.ftLastWriteTime,
                                        &srcFiles[i].fd.ftLastWriteTime) < 0) 
                    {
                        // src file is new than dest file
                        srcFiles[i].bIsNew = TRUE;
                    }
                    break;  // break j loop, because found!
                }
            }
        }
                    
        // printf("j=%d  ", j);
        if (bFound == FALSE) // not found, so is new.
            srcFiles[i].bIsNew = TRUE;
    }
        
        
    // updating new files ...
    for (i=0, j=0; i<iSrcFiles; i++) 
    {  
        // j for new files counter
        if (srcFiles[i].bIsNew) 
        {
            printf("%s\n", srcFiles[i].fd.cFileName);
            j++;
        } 
    }
        
    if (j==0) 
    {
        printf("no file new \n");
        //printf("没有最新的文件 \n");
    }
    else 
    {
        printf("There are %d files need to be updated \n", j);
        printf("if you do not want to update these files, press Ctrl-Break \n");
        printf("otherwise anykey...\n");
        //printf("Τ %d 郎惠璶穝 \n", j);
        //printf("狦ぃ稱穝硂ㄇ郎叫 Ctrl-Break \n");
        //printf("玥叫ヴ種龄...\n");
        getch();
    }
        
    for (i=0; i<iSrcFiles; i++) 
    {
        // printf("srcFiles[%d].filename = %s \n", i, srcFiles[i].fd.cFileName);
        // printf("srcFiles[%d].bIsNew = %d \n", i, srcFiles[i].bIsNew);
                
        if (srcFiles[i].bIsNew) 
        {
            strcpy(dest, destpath);
            strcat(dest, srcFiles[i].fd.cFileName);
            //CopyFile(srcFiles[i].fd.cFileName, dest, FALSE); // FALSE means overwrite
            //printf("copy %s %s \n", srcFiles[i].fd.cFileName, dest);
            strcpy(src, srcpath); 
            strcat(src, srcFiles[i].fd.cFileName); 
            CopyFile(src, dest, FALSE); 
            printf("copy %s %s \n", src, dest);
        }
    }
        
        
    // deleting redudant files...
    // printf("redundant files :\n");
    for (j=0, i=0; j<iDestFiles; j++) 
    {
        // i for redudant files counter
        if (!destFiles[j].bMatch) 
        {
            printf("%s\n", destFiles[j].fd.cFileName);
            i++;
        }
    }
        
    if (i==0) 
    {
        printf("no redudant file \n");
        //printf("⊿Τヴ仑緇郎惠璶埃 \n");
    }
    else 
    {
        printf("There are %d files need to be deleted \n", i);
        printf("if you do not want to delete those files, press Ctrl-Break \n");
        printf("otherwise anykey...\n");
        //printf("Τ %d 郎惠璶埃 \n", i);
        //printf("狦ぃ稱炳奔硂ㄇ郎叫 Ctrl-Break \n");
        //printf("玥叫ヴ種龄...\n");
        getch();
    }
        
    for (j=0; j<iDestFiles; j++) 
    {
        // printf("destFiles[%d].filename = %s \n", j, destFiles[j].fd.cFileName);
        // printf("destFiles[%d].bMatch = %d \n", j, destFiles[j].bMatch);
                
        if (!destFiles[j].bMatch) 
        {
            strcpy(dest, destpath);
            strcat(dest, destFiles[j].fd.cFileName);
            DeleteFile(dest);
            // printf("delete %s \n", dest);
        }
    }
}

