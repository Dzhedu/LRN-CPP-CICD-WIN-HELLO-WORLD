# LRN-CPP-CICD-WIN-HELLO-WORLD
```
Показывает шаги для CI/CD.  
Программа Hello World на C++.   
MSVS 2022.
```

**0// Создаем на GitHub репозиторию LRN-CPP-CICD-WIN-HELLO-WORLD (GITIGNORE + README.md +).**  
  
**1// Создаем новый пустой проект С++ в MSVS2022 под названием LRN-CPP-CICD-WIN-HELLO-WORLD.**  
  
**2// Специалист делает настройку репозитория в Developer Command Prompt v17.14.11:**  
```
set CR=LRN-CPP-CICD-WIN-HELLO-WORLD  
set CB=main  
cd %CR%  
git init  
git branch -M %CB%  
git remote add %CR% git@github.com:Dzhedu/LRN-CPP-CICD-WIN-HELLO-WORLD.git  
git pull %CR% %CB%
```
  
**3// Редактируем .gitignore в редакторе Notepad++. Добавляем в начало файла строки и сохраняем.**  
```
\# MSVS2022  
.vs/  
*.sln  
*.vcxproj  
*.vcxproj.filters  
*.vcxproj.user
```
**Добавляем в индекс, коммитим, и пушим изменения:**
```
git add .gitignore  
git commit -m "chore: update .gitignore"  
git push %CR% %CB%
```
  
**4// Создаем в проекте файл LRN-CPP-CICD-WIN-HELLO-WORLD.cpp и заголовочный файл LRN-CPP-CICD-WIN-HELLO-WORLD.h.**  

**LRN-CPP-CICD-WIN-HELLO-WORLD.cpp**  
```
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
```
**LRN-CPP-CICD-WIN-HELLO-WORLD.h**  
```
#pragma once

class HelloWorld {
public:
    void Print() const;
};
```

**5// Добавляем оба файла в индекс, коммитим, пушим.**  
```
git add LRN-CPP-CICD-WIN-HELLO-WORLD.cpp
git add LRN-CPP-CICD-WIN-HELLO-WORLD.h
git commit -m "Line 1"
git push %CR% %CB%
```

**6// Сделаем сборку локально. В Developer Command Prompt v17.14.11:**  
```
set CP=LRN-CPP-CICD-WIN-HELLO-WORLD
cl /EHsc %CP%.cpp /Fe"C:\Users\User\source\prod\%CP%.exe"
```

**7// Проверяем работу.**  
```
c:\Users\User\source\prod\%CP%.exe
```  
**Вывод на экране:**  
```
c:\Users\User\source\repos\LRN-CPP-CICD-WIN-HELLO-WORLD>c:\Users\User\source\prod\%CP%.exe
Hello World

```

**8// Делаем автоматическую сборку через GitHub Actions. Добавляем каталоги .github\workflows\. Там создаем файл LRN-CPP-CICD-WIN-HELLO-WORLD.yml**  
```
mkdir .github\workflows
copy nul .github\workflows\%CP%.yml
```

**9// Добавляем данные и сохраняем файл.**  

**LRN-CPP-CICD-WIN-HELLO-WORLD.yml**  
```
name: Build and Package LRN-CPP-CICD-WIN-HELLO-WORLD.exe on Windows

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build:
    runs-on: windows-2025

    steps:
    - name: Checkout repository
      uses: actions/checkout@v4

    - name: Set up MSVC environment
      uses: ilammy/msvc-dev-cmd@v1

    - name: Compile LRN-CPP-CICD-WIN-HELLO-WORLD.cpp
      run: cl /EHsc LRN-CPP-CICD-WIN-HELLO-WORLD.cpp

    - name: Create ZIP archive
      run: |
        powershell Compress-Archive -Path LRN-CPP-CICD-WIN-HELLO-WORLD.exe -DestinationPath LRN-CPP-CICD-WIN-HELLO-WORLD.zip

    - name: Upload ZIP as artifact
      uses: actions/upload-artifact@v4
      with:
        name: main-package
        path: LRN-CPP-CICD-WIN-HELLO-WORLD.zip
```

**//10 Добавляем файл в индекс, коммитим, пушим.**  

```
git add .github\workflows\%CP%.yml
git commit -m "Autobuild file added"
git push %CR% %CB%
```

**//11 **




