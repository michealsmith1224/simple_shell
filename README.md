<p align="center">
  
  <img src="the gate.jpg" width="600\"/>
  
  <br>
  
  <h1><p align="center"> The Gates of Shell</h></p></font>
  
 ## NAME
  **simple_shell** - command
  interpreter (shell)
  
 # SYNOPSIS
  **simple_shell** [command_file]
  
 # DESCRIPTION
  **simple_shell** 
  is custom command interpreter for the system.
  
  * **Overwiew**

  The simple_shell is a command that reads lines from either a file or the terminal, intereprets them, and generally executes other commands. It is the program a user could run on logging into the system (it can be set as default shell with the chsh(1) command). The simple_shell implements a lamguage that has flow control constructs, a macro facility that provides a variety of features in addition to data storage, along with built in history and line editing capabilities. It incorporates many features to aid interactive use and has the advantage that the interpretative language is common to both interactive and non-interactive use (shell scripts). That is, commands can be typed directly to the running shell or can be put into a file and the file can be executed directly by the shell.

* **Invocation**

  If no args are present and if the standard input of the shell is connected to a terminal, the shell is considered an interactive shell. An interactive shell generally prompts before each command and handles programming and command errors differently (as described below).

  If command line argument `command_file` has been specified, then the shell treats it as the name of a file from which to read commands (a shell script). Otherwise, the shell reads commands from its standard input.

* **Lexical Structure**

  The simple_shell reads input in terms of lines from a file and breaks it up into words at whitespace (blanks and tabs), and at certain sequences of characters that are special to the shell called `operators`. Following is a list of operators (their meaning is discussed later) :
  * Control operators:
    `&&` `;` `||`

* **Aliases**

  An alias is a name and corresponding value set using the alias builtin command. The shell checks the word to see if it matches an alias, If it does, it replaces it in the input stream with its value. For example, if there is an alias called `lf` with the value `ls -F`, then the input:

  ```Shell
  lf foobar
  ```
    would become
  ```Shell
  ls -F foobar
  ```
  Aliases provide a convenient way for native users to create shorthands for commands without having to learn how to create functions with arguments. They can also be used to create lexically obscure code. This use is discouraged.

* **Commands**

  The shell interprets the words it reads according to a language. Essentially though, a line is read and the first word of the line is recognized as a simple command.  Otherwise, a complex command or some other special construct may have been recognized.

* **Simple Commands**

  If a simple command has been recognized, the words are expanded as described in the section called “Expansions”, and the first remaining word is considered the command name and the command is located. The remaining words are considered the arguments of the command.

* **Search and Execution**

  There are two types of commands: builtin commands, and normal programs -- and the command is searched for (by name) in that order. They each are executed in a different way.

  Shell builtins are executed internally to the shell, without spawning a new process.
Otherwise, the command is searched for as a normal program in the file system (as described in the next section). The shell will interpret the program in a subshell.

* **Getline**
  
  The ``getline()`` function is prototyped in the ``stdio.h`` header file.
  threre are three arguments
  ``&buffer``
  ``&size``
  ``stdin``
 The getline function uses the realloc function to automatically increase the memory block as required, ensuring that there is never a space shortage. This is one of the explanations why getline is safe. The value returned inside the second parameter will also inform us of the new block size. It returns ``-1`` if an error appears, such as reaching the end of a file without receiving any bytes. Getline functions cease reading input from the stream when they meet a newline character or the end of a file.

* **Path Search**

  When locating a command, the shell first looks for a builtin command by that name. If a builtin command is not found, one of two things happen:
  1) Command names containing a slash are simply executed without performing any searches.
  2) The shell searches each entry in PATH in turn for the command. The value of the PATH variable should be a series of entries separated by colons. Each entry consists of a directory name. The current directory may be indicated implicitly by an empty directory name, or explicitly by a single period.

* **Command Exit Status**

  Each command has an exit status that can influence the behaviour of other shell commands. The paradigm is that a command exits with zero for normal or success, and non-zero for failure, error, or a false indication. The man page for each command should indicate the various exit codes and what they mean. Additionally, the builtin commands return exit codes, as does an executed shell function.

* **Short-Circuit List Operators**

  `&&` and `||` are AND-OR list operators. `&&` executes the first command, and then executes the second command if the exit status of the first command is zero. `||` is similar, but executes the second command if the exit status of the first command is nonzero.  `&&` and `||` both have the same priority.

* **Special Parameters**

  **?** - Expands to the exit status of the most recent pipeline.

  **$** - Expands to the process ID of the invoked shell.  A subshell retains the same value of `$` as its parent.

* **Parameter Expansion**

  The format for parameter expansion is as follows:

  ``$expression``

* **White Space Splitting (Field Splitting)**

  The shell treats each whitespace or tab to split the results of parameter expansion into fields.
