# Game Boy Emulator 🎮

Bem-vindo ao projeto de emulador de Game Boy! Se você chegou até aqui, provavelmente está curioso em ver esse emulador em ação no seu PC. Bora lá configurar tudo?

## Passo a Passo para Configuração 🚀

### 1. Clonando o Repositório 🖥️

Primeiro de tudo, clone este repositório:

```bash
git clone https://github.com/seu_usuario/nome_do_repositorio.git
cd nome_do_repositorio
```
### 2. Instalando o CMake e o Compilador 🛠️
Para compilar o projeto, vamos utilizar o **CMake** em conjunto com **MSYS2** e **MinGW-w64**.

#### 2.1. Instalando o MSYS2 e MinGW-w64.
##### 1. Baixe e instale o MSYS2:
- Acesse a página oficial do MSYS2 e siga as instruções de instalação para Windows.

##### 2. Abra o MSYS2:
- Após a instalação, abra o terminal **MSYS2** (você pode encontrá-lo no menu Iniciar).

##### 3. Atualize os pacotes:
- Execute os seguintes comandos no terminal para atualizar os pacotes do **MSYS2**:
```bash
pacman -Syu
```

##### 4. Instale o MinGW-w64:
- Para instalar o MinGW-w64, execute:
```bash
pacman -S mingw-w64-x86_64-toolchain
```

##### 5. Adicione o MinGW ao PATH:
- Adicione o diretório do **MinGW** ao seu PATH.
- Certifique-se de que o caminho onde o **MinGW** está instalado (geralmente **C:\msys64\mingw64\bin**) esteja incluído nas variáveis de ambiente do sistema. Você pode fazer isso através das configurações do sistema no Windows.

##### 6. Verifique a instalação:
- Abra um terminal e digite:
```bash
g++ --version
```
- Se estiver instalado corretamente, você verá a versão atual do g++ exibida no terminal.

#### 2.2. Instalando o CMake.
Agora vamos instalar o CMake, que será responsável pela geração dos arquivos de build.

##### 1. Baixe o CMake:
- Vá até o site oficial do CMake: https://cmake.org/download/ e baixe a versão para o seu sistema operacional (Windows, Linux ou Mac).

##### 2. Instale o CMake:
- Siga o processo de instalação padrão. No Windows, certifique-se de marcar a opção para adicionar o CMake ao **PATH**.

##### 3. Verifique a instalação:
- Abra um terminal e digite:
```bash
cmake --version
```
- Se o CMake estiver instalado corretamente, você verá a versão atual do CMake exibida no terminal.

### 3. Instalando a SDL2 🎮
Aqui é onde entra a dependência do **SDL2**. Precisamos configurar isso para que o projeto funcione bonitinho.

##### 1. Baixe a SDL2:
- Link direto:  https://github.com/libsdl-org/SDL/releases/download/release-2.30.7/SDL2-devel-2.30.7-mingw.tar.gz
- Ou vá para o site oficial da SDL2: https://www.libsdl.org/ em **SDL Releases** e escolha a versão que corresponde ao seu sistema operacional (Windows, Mac ou Linux).

##### 2. Extraia e configure:
- Depois de baixar, extraia o ZIP da SDL2 em uma pasta de sua escolha.
- Copie a pasta lib da SDL2 para a raiz do projeto. A estrutura ficará assim:
```bash
/root/
├── /include/ 
├── /lib/      <-- você vai adicionar
├── /src/
```

##### 3. E sobre a pasta bin da SDL2?:
- A pasta bin contém o arquivo SDL2.dll. Coloque o arquivo SDL2.dll na pasta build do seu projeto.
- Ops, não tem pasta build ainda? Sem problema! Basta criar uma nova pasta chamada build na raiz do projeto e jogar o SDL2.dll lá dentro:
```bash
/root/
├── /build/
│   └── SDL2.dll
```

### 4. Compilando o Projeto com CMake 🔨
Agora vamos configurar e compilar o projeto usando CMake.

##### 1. Gerando os arquivos de build:
- Abra o terminal (no VSCode ou MSYS2) e, na raiz do projeto, execute:
```bash
cd build
cmake .. -G "MinGW Makefiles"
```
- Isso vai gerar os arquivos de build na pasta build.

##### 2. Compilando o projeto:
- Após gerar os arquivos, você pode compilar o projeto com o comando:
```bash
mingw32-make
```
 - Isso criará o executável **emulator.exe** na pasta **build**.

### 5. Executando o Emulador 🕹️
Depois de compilar, você pode rodar o emulador diretamente no terminal.

- Abra o terminal no VSCode, considerando que está na raiz do projeto execute:
```bash
./build/emulator.exe
```

### 6. E se eu estiver usando Linux ou Mac? 🐧🍏
Se você não estiver no Windows, a configuração pode variar um pouco. Aqui vão algumas dicas gerais:
- Linux: Instale a SDL2 e CMake pelo gerenciador de pacotes da sua distribuição (ex.: sudo apt install cmake libsdl2-dev).
- Mac: Instale a SDL2 e CMake com o Homebrew:
```bash
brew install cmake sdl2
```

Por favor, tenha em mente que este projeto foi desenvolvido usando o Windows e o Visual Studio Code, então você pode ter que lidar com algumas diferenças de configuração se optar por outra IDE ou sistema operacional.