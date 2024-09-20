# Game Boy Emulator 🎮

Bem-vindo ao projeto de emulador de Game Boy! Se você chegou até aqui, provavelmente está curioso em ver esse emulador em ação no seu PC. Bora lá configurar tudo?

## Passo a Passo para Configuração 🚀

### 1. Clonando o Repositório 🖥️

Primeiro de tudo, clone este repositório:

```bash
git clone https://github.com/seu_usuario/nome_do_repositorio.git
cd nome_do_repositorio
```
### 2. Instalando o Compilador 🛠️
Para compilar o projeto, vamos utilizar o **MSYS2** com **MinGW-w64**. Siga as instruções abaixo para instalá-los:

**1. Baixe e instale o MSYS2:**
- Acesse a página oficial do **MSYS2** e siga as instruções de instalação para Windows.

**2. Abra o MSYS2:**
- Após a instalação, abra o terminal **MSYS2** (você pode encontrá-lo no menu Iniciar).

**3. Atualize os pacotes:**
- Execute os seguintes comandos no terminal para atualizar os pacotes do **MSYS2**:

	```bash
	pacman -Syu
	```

**4. Instale o MinGW-w64:**
- Para instalar o MinGW-w64, execute:
	```bash
	pacman -S mingw-w64-x86_64-toolchain
	```

**5. Adicione o MinGW ao PATH:**
- Adicione o diretório do **MinGW** ao seu PATH. No terminal, você pode verificar onde o **MinGW** está instalado com:
	```bash
	where g++
	```
- Certifique-se de que o caminho onde o **MinGW** está instalado (geralmente **C:\msys64\mingw64\bin**) esteja incluído nas variáveis de ambiente do sistema. Você pode fazer isso através das configurações do sistema no Windows.

### 3. Instalando a SDL2 🎮
Aqui é onde entra a dependência do **SDL2**. Precisamos configurar isso para que o projeto funcione bonitinho.

**1. Baixe a SDL2:**
- Link direto:  https://github.com/libsdl-org/SDL/releases/download/release-2.30.7/SDL2-devel-2.30.7-mingw.tar.gz

ou:
- Vá para o site oficial da **SDL2**: SDL Releases: https://www.libsdl.org/
- Escolha a versão que corresponde ao seu sistema operacional (Windows, Mac ou Linux).

**2. Extraia e configure:**
- Depois de baixar, extraia o ZIP da SDL2 em uma pasta de sua escolha.
- Copie as pastas include e lib da SDL2 para a raiz do projeto. A estrutura ficará assim:
```bash
/root/
├── /src/
├── /include/  <-- você vai adicionar isso
├── /lib/      <-- você vai adicionar isso também
```

**3. E sobre a pasta bin da SDL2?:**
- A pasta bin contém o arquivo SDL2.dll. Coloque o arquivo SDL2.dll na pasta bin do seu projeto.
- Ops, não tem pasta bin ainda? Sem problema! Basta criar uma nova pasta chamada bin na raiz do projeto e jogar o SDL2.dll lá dentro:
```bash
/root/
├── /bin/
│   └── SDL2.dll
```

### 4. Compilando o Projeto 🔨
Agora vamos compilar o projeto! O arquivo **tasks.json** já vem configurado no repositório, mas você vai precisar ajustar o caminho dos arquivos no "args" para corresponder à estrutura do seu PC.

**1. Abrir o Visual Studio Code (ou sua IDE de preferência):**
- Abra o terminal e execute o seguinte comando para abrir o VSCode na pasta do projeto(lembrando que deverá estar na root do seu projeto):
```bash
code .
```

**2. Ajuste o Caminho no tasks.json:**
- Abra o arquivo `.vscode/tasks.json` no VSCode e altere o caminho do arquivo `*.cpp` e o caminho de saída do executável para refletir os diretórios no seu PC:
```
    {
    	"label": "Build",
    	"type": "shell",
    	"command": "g++",
    	"args": [
    		"-g",
    		"C:/seu_caminho_para_o_projeto/src/*.cpp",  // ajuste aqui
    		"-o",
    		"C:/seu_caminho_para_o_projeto/bin/emulator.exe"  // e aqui
    	],
    	...
    }
```
 - **Atenção**: Nem todos os ambientes suportam essa sintaxe de wildcard(`*.cpp`), então pode não funcionar em todos os casos. Se esse método não funcionar, você pode considerar criar um script de compilação.

**3. Criar um script de compilação(SE FOR O CASO):**
	No caso do seu ambiente não suportar a sintaxe de wildcard anterior, tente isso, caso contrário pule essa etapa.

- Você pode criar um pequeno script (como um arquivo `.sh` ou `.bat`) que compile todos os arquivos e chamar esse script a partir do `tasks.json`. Por exemplo, crie um arquivo chamado `compile.bat` com o seguinte conteúdo:
```bat
@echo off
g++ -g C:/seu_caminho_para_o_projeto/src/*.cpp -o C:/seu_caminho_para_o_projeto/bin/emulator.exe
```
- Depois, você chamaria esse script no `tasks.json`:
```json
"args": [
	"C:/seu_caminho_para_o_projeto/compile.bat"
],
```

**4. Compilando:**
- Depois de ajustar os caminhos, pressione Ctrl + Shift + B no VSCode para compilar o projeto. Isso vai gerar o arquivo executável emulator.exe na pasta bin do projeto.

### 5. Executando o Emulador 🕹️
Agora, bora rodar! Depois de compilar, você pode executar o emulador diretamente:

- No terminal do VSCode (ou no Prompt de Comando), rode:
```bash
./bin/emulator.exe
```

### 6. E se eu estiver usando Linux ou Mac? 🐧🍏
Se você não estiver no Windows, a configuração pode variar um pouco. Aqui vão algumas dicas gerais:
- Linux: Você pode instalar a SDL2 pelo gerenciador de pacotes da sua distribuição (ex.: apt, yum, etc.). Depois, ajuste o tasks.json para os caminhos corretos.
- Mac: Dá para instalar a SDL2 com o Homebrew (brew install sdl2) e ajustar os caminhos no tasks.json.

Por favor, tenha em mente que este projeto foi desenvolvido usando o Windows e o Visual Studio Code, então você pode ter que lidar com algumas diferenças de configuração se optar por outra IDE ou sistema operacional.