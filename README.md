# LRN-CPP-CICD-WIN-HELLO-WORLD

Показывает шаги для CI/CD.  
Программа Hello World на C++.   
MSVS 2022.  

0// Специалист создает на GitHub репозиторию LRN-CPP-CICD-WIN-HELLO-WORLD (GITIGNORE + README.md +).  
  
1// Специалист создает новый пустой проект С++ в MSVS2022 под названием LRN-CPP-CICD-WIN-HELLO-WORLD.  
  
2// Специалист делает настройку репозитория в Developer Command Prompt v17.14.11:  
set CR=LRN-CPP-CICD-WIN-HELLO-WORLD  
set CB=main  
cd %CR%  
git init  
git branch -M %CB%  
git remote add %CR% git@github.com:Dzhedu/LRN-CPP-CICD-WIN-HELLO-WORLD.git  
git pull %CR% %CB%  
  
3// Специалист редактирует .gitignore в редакторе Notepad++. Добавляет в начало строки и сохраняет.
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
  
4// Специалист делает стандоф для проектов C++. В Developer Command Prompt v17.14.11:  
mkdir src include tests  
  
5// 
  



