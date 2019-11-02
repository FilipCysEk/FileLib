//
// Created by cysiu on 20.10.2019.
//

#ifndef LIBRARIES1_FILELIB_H
#define LIBRARIES1_FILELIB_H
#include <iostream>
#include <experimental/filesystem>
#include <string>

using namespace std;
namespace fs = experimental::filesystem;


class FileLib {
public:
    /**
     * @brief Convert relative file path to static file path
     * @param path relative path to file/directory
     * @return static path to file/directory (directory have on end '/')
     */
    string getFullPath(string path);

    /**
     * @brief CHeck existing of file/directory
     * @param path static path to file/directory
     * @return 1 - exists, 0 - no exist
     */
    bool fileExist(string path);

    /**
     * @brief Return file modification time
     * @param path static path to file
     * @return last modification time
     */
    time_t fileTime(string path);

    /**
     * @brief Creating directory
     * @param name name of new directory
     * @param path static path to directory, where directory be created
     * @return 1 - successfully, 0 - error
     */
    bool createDirectory(string name, string path);
    /**
     * @brief Creating directory
     * @param path static path to new directory
     * @return 1 - successfully, 0 - error
     */
    bool createDirectory(string path);

    /**
     * @brief Remove file/directory
     * @param path static path to removed file/directory
     * @return 1 - successfully, 0 - error
     */
    bool removeFile(string path);

    /**
     * @brief Remove all files from directory
     * @param path static file to directory
     * @return 1 - successfully, 0 - error
     */
    bool emptyingDirectory(string path);

    /**
     * @brief rename file/directory
     * @param oldName old name of file
     * @param newName new name of file
     * @param path static path to directory, where this file is
     */
    void rename(string oldName, string newName, string path);

    /**
     * @brief Rename file/directory
     * @param oldFilePath static path to old file with name
     * @param newFilePath static path to new file with name
     */
    void rename(string oldFilePath, string newFilePath);

    /**
     * @brief Copy file/firectory
     * @param oldPath static path to source file
     * @param newPath static path to paste file
     */
    void copy(string oldPath, string newPath);

    /**
     * @brief Move file/directory
     * @param oldPath static path to actually file
     * @param newPath static path to new file location
     */
    void move(string oldPath, string newPath);


};


#endif //LIBRARIES1_FILELIB_H
