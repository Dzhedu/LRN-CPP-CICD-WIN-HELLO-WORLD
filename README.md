# LRN-CPP-CICD-WIN-HELLO-WORLD

Показывает шаги для CI/CD.  
Программа Hello World на C++.   
MSVS 2022.  

0// Создать репозиторию LRN-CPP-CICD-WIN-HELLO-WORLD  

1// Специалист создаем новый проект в MSVS2022 под названием LRN-CPP-CICD-WIN-HELLO-WORLD.  
Пустой проект C++  

2// Специалист делает настройку репозитория в Developer Command Prompt v17.14.11:  
set CR=LRN-CPP-CICD-WIN-HELLO-WORLD  
set CB=main  
cd %CR%  
git init  
git branch -M %CB%  
git remote add %CR% git@github.com:Dzhedu/LRN-CPP-CICD-WIN-HELLO-WORLD.git  
git pull %CR% %CB%  
  
2// Специалист делает стандоф для проектов C++. В Developer Command Prompt v17.14.11:  
mkdir src include tests  
  
3// Специалист создаем новый проект в MSVS2022 в директории LRN-CPP-CICD-WIN-HELLO-WORLD.  
Пустой проект C++  


