# MandelExplorer

<h2> Building</h2>
<li> To build on MinGW g++ for Windows, download SFML (DW2) 32 Bit <a href="https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip">here</a>. <br><li> Place the include and lib directories inside of the src folder. <br>
<li>Copy and paste all of the DLLs in the bin folder of the SFML download and place them into the root of this project directory. <br>
<li>To stop include errors in VSCode, open the VSCode Settings UI (Ctrl+Comma) and search for "Compiler"
<li>Make sure that G++ is set as your Default Compiler path
<li>Add </li>
        
    "C_Cpp.default.includePath": [
            "${workspaceFolder}/**"
        ],

to the bottom of the `settings.json` file
<li>To compile and run, just run `make`.</li>
A much better explanation of this setup can be found at this YouTube video: 
<br>
<iframe width="640"  height="360"  
src="https://www.youtube.com/embed/Ljhpsdz8Ouo">  
</iframe>
