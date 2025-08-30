# LRN-CPP-CICD-WIN-HELLO-WORLD

Показывает шаги для CI/CD.  
Программа Hello World на C++.   
MSVS 2022.  

**0// Создаем на GitHub репозиторию LRN-CPP-CICD-WIN-HELLO-WORLD (GITIGNORE + README.md +).**  
  
1// Создаем новый пустой проект С++ в MSVS2022 под названием LRN-CPP-CICD-WIN-HELLO-WORLD.  
  
2// Специалист делает настройку репозитория в Developer Command Prompt v17.14.11:  
set CR=LRN-CPP-CICD-WIN-HELLO-WORLD  
set CB=main  
cd %CR%  
git init  
git branch -M %CB%  
git remote add %CR% git@github.com:Dzhedu/LRN-CPP-CICD-WIN-HELLO-WORLD.git  
git pull %CR% %CB%  
  
3// Редактируем .gitignore в редакторе Notepad++. Добавляем в начало файла строки и сохраняем.  
\# MSVS2022  
.vs/  
*.sln  
*.vcxproj  
*.vcxproj.filters  
*.vcxproj.user  
Специалист добавляет в индекс, коммитит, и пушит изменения:  
git add .gitignore  
git commit -m "chore: update .gitignore"  
git push %CR% %CB%  
  
4// Создаем в проекте файл LRN-CPP-CICD-WIN-HELLO-WORLD.cpp и заголовочный файл LRN-CPP-CICD-WIN-HELLO-WORLD.h.  

**LRN-CPP-CICD-WIN-HELLO-WORLD.cpp**  
  
#include "LRN-CPP-CICD-WIN-HELLO-WORLD.h"
#include <iostream>

void HelloWorld::Print() const {
    std::cout << "Hello World" << std::endl;
}

int main() {
    HelloWorld hw;
    hw.Print();
    return 0;
}  

**LRN-CPP-CICD-WIN-HELLO-WORLD.h**  
  
#pragma once

class HelloWorld {
public:
    void Print() const;
};  
  

5// 
  



