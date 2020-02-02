//
// Created by cysiu on 20.10.2019.
//

#include "../include/FileLib.h"

string FileLib::getFullPath(string path) {
    if (path.find('\\') == string::npos) {
        if (path.size() != 0) {
            //Passed absolute path?
            if (!(path[0] == '/' || (path[1] == ':' && path[2] == '/'))) {
                path = fs::current_path().string() + '/' + path;
            }
            //Checking last sign is /
            if (path[path.size() - 1] == '/')
                return path;
            else {
                for( int p = path.size() - 1; p > 0; p--){
                    if(path[p] == '/') break;

                    if(path[p] == '.') return path;
                }
                return path + "/";
            }
        } else {
            return fs::current_path().string() + '/';
        }
    } else {
        throw "Unexcepted \\ in path";
    }
}

bool FileLib::fileExist(string path) {
    if(isStaticPath(path))
        return fs::exists(path);
    else
        throw "Passed relative path";
}

time_t FileLib::fileTime(string path) {
    if(isStaticPath(path)){
        auto fileTime = fs::last_write_time(path);
        return decltype(fileTime)::clock::to_time_t(fileTime);
    }
    else
        throw "Passed relative path";
}

bool FileLib::isStaticPath(string path) {
    return path[0] == '/' || (path[1] == ':' && path[2] == '/');
}

bool FileLib::isStaticDirPath(string path) {
    return (path[0] == '/' || (path[1] == ':' && path[2] == '/')) && path[path.size() - 1] == '/';
}

bool FileLib::createDirectory(string name, string path) {
    if(isStaticDirPath(path)){
        createDirectory(path + name);
    }
    else
        throw "Passed relative path or file path";
}

bool FileLib::createDirectory(string path) {
    if(isStaticPath(path)){
        return fs::create_directories(path);
    }
    else
        throw "Passed relative path";
}

bool FileLib::removeFile(string path) {
    if(isStaticPath(path)){
        return fs::remove_all(path);
    }
    else
        throw "Passed relative path";
}

bool FileLib::emptyingDirectory(string path) {
    if(isStaticPath(path)){
        short res = 0;
        res += fs::remove_all(path);
        res += createDirectory(path);
        return res == 2;
    }
    else
        throw "Passed relative path";
}

void FileLib::rename(string oldName, string newName, string path) {
    if(isStaticPath(path)){
        rename(path + oldName, path + newName);
    }
    else
        throw "Passed relative path";
}

void FileLib::rename(string oldFilePath, string newFilePath) {
    if(isStaticPath(oldFilePath) && isStaticPath(newFilePath)){
        fs::rename(oldFilePath, newFilePath);
    }
    else
        throw "Passed relative path";
}

void FileLib::copy(string oldPath, string newPath) {
    if(isStaticPath(oldPath) && isStaticPath(newPath)){
        fs::copy(oldPath, newPath);
    }
    else
        throw "Passed relative path";
}

void FileLib::move(string oldPath, string newPath) {
    rename(oldPath, newPath);
}

vector<string> FileLib::dirFiles(string path) {
    if(isStaticDirPath(path)){
        vector<string> files;
        for(const auto &entry : fs::directory_iterator(path)){
            if(entry.path() != "." || entry.path() != ".."){
                files.push_back(entry.path());
            }
        }

        return files;
    } else
        throw "Passed relative path or path to file";

}


