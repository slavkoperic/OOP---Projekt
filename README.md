# OOP---Projekt

## Windows

### Upute za prvo pokretanje igre

1. git clone https://github.com/slavkoperic/OOP---Projekt.git  
2. U VisualStudiu ili drugom IDE-u napraviti novi prazan c++ projekt.  
3. U "source files" pod "Add existing item" dodati sve .h i .cpp datoteke.  
4. Build Solution  
5. Start Windows Debugger  

### Upute za sljedeće pokretanje igre

1. Pozicionirati se u C:\FilePath\OOP---Projekt\Naziv_Projekta\x64\Debug\
2. Pokrenuti  Naziv_Projekta.exe
 
## Linux

### Ovisno o potrebi instalirati c++ compiler

1. sudo apt update  
2. sudo apt install g++  

### Ako compiler već postoji

1. git clone https://github.com/slavkoperic/OOP---Projekt.git  
2. cd Projekt  
3. g++ main.cpp -o igra  
4. ./igra  

## Kako igrati

Nakon uspješnog pokretanja igre čitati ispis na ekranu te odabrati lika koristeći opcije **1** ili **2**.  

Nakon odabira lika igra počinje te brojevima **1**, **2**, **3** igrač odlučuje svoj idući korak.  

Prilikom odabira opcije **3** igrač dobiva izbor **Health/Mana** – odabir je važno napisati prvim velikim slovom jer je izbor **case sensitive**.


