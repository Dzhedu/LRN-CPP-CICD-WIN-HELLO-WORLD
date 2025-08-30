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

**//11 Так как триггером для запуска автосборки является любой пуш, то мы должны сразу получить готовый артефакт.**  
**Заходим в GitHub Actions. Смотрим что сборка успешная, качаем артефакт, проверяем его работу.**  

**//12 Скачаем артефакт с помощью скрипта на PowerShell. В дериктории prod создаем скрипт lisa6_artfact_downloader.ps1 и записываем данные.**  

**lisa6_artfact_downloader.ps1**  

```
## Artefact Downloader
param (
    [Parameter(Mandatory=$true)]
    [string]$Owner,

    [Parameter(Mandatory=$true)]
    [string]$Repo,

    [Parameter(Mandatory=$true)]
    [string]$ArtifactId,

    [Parameter(Mandatory=$true)]
    [string]$Token,

    [switch]$CleanUp
)

#
$apiUrl = "https://api.github.com/repos/$Owner/$Repo/actions/artifacts/$ArtifactId/zip"
$zipFile = "artifact_$ArtifactId.zip"`

# 
$headers = @{
    Authorization = "Bearer $Token"
    Accept        = "application/vnd.github.v3+json"
}

Write-Host "Download processing $ArtifactId from $Owner/$Repo..."
Invoke-WebRequest -Uri $apiUrl -Headers $headers -OutFile $zipFile

Write-Host "Unzip processing..."
Expand-Archive -Path $zipFile -Force

if ($CleanUp) {
    Write-Host "Delete temp files processing..."
    Remove-Item $zipFile
}

Write-Host "Artifact downloaded and unziped!"
```

**//13 Запускаем скрипт, предаем правильные аргументы, проверяем работу.**  

```
PS C:\Users\User\source\prod> .\lisa6_artfact_downloader.ps1 `
>> -Owner "Dzhedu" `
>> -Repo $CR `
>> -ArtifactId "3889955827" `
>> -Token $Token `
>> -CleanUp
Download processing 3889955827 from Dzhedu/LRN-CPP-CICD-WIN-HELLO-WORLD...
Unzip processing...
Delete temp files processing...
Artifact downloaded and unziped!
PS C:\Users\User\source\prod>
```

**//14 Запускаем программу LRN-CPP-CICD-WIN-HELLO-WORLD.exe, убеждаемся что она работает корректно.**  

#Итог  

** Мы посмотрели работу GitHub CI/CD на простом примере Hello World на C++ на MSVS2022.**





