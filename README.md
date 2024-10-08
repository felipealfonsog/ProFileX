### ProFileX [(Experimental Project)](#important-experimental-project)* 
##### - Under development -
ProFileX is a Linux file management tool with a GTK3-based GUI. It allows users to list, create, and delete files easily, providing an intuitive interface for efficient file operations.

ProFileX is an advanced file management tool designed for Linux systems, featuring a user-friendly GTK3-based graphical interface. With ProFileX, users can effortlessly navigate, manipulate, and organize files and directories with ease. The application offers robust functionalities such as file listing, creation, deletion, and seamless navigation through directories. Its intuitive design ensures efficient file operations, catering to both novice and advanced users alike. ProFileX prioritizes simplicity and efficiency, making it an essential tool for anyone seeking a lightweight and powerful file manager on Linux.

> [!WARNING]
> This project is a dynamic work in progress. Version 1.0.0, the inaugural stable and fully-featured release, 
> is on the horizon. While it's not yet recommended for daily use due to potential minor inconveniences,
> we welcome enthusiasts to help uncover and resolve bugs or propose exciting new features. But if you wanna try, you are more than welcome!

# 

[![ProFileX Philosophy](https://img.shields.io/badge/ProFileX-Philosophy-green)](#)

At its core, ProFileX embodies a philosophy centered around simplicity, minimalism, and lightweight design. The project aims to provide Linux users with a file management solution that maximizes functionality while minimizing resource consumption. By focusing on essential features and an intuitive user experience, ProFileX eliminates unnecessary complexities commonly found in traditional file managers. This minimalist approach not only enhances usability but also contributes to a faster and more responsive user interface. ProFileX stands as a testament to the belief that software can be both powerful and lightweight, offering a streamlined alternative for efficient file management on Linux systems.

#

[![Warning: This Project is Unstable](https://img.shields.io/badge/Warning-This_Project_is_Unstable-black)](#)

<sub>* This is currently an experimental phase where the primary focus is on making the system functional and establishing a practical and logical pathway that aligns with both my vision and the project's goals. It might contain errors, bugs, etc. Many other non-core elements of the project are considered secondary.</sub>

![Version](https://img.shields.io/github/release/felipealfonsog/ProFileX.svg?style=flat&color=blue)
![Main Language](https://img.shields.io/github/languages/top/felipealfonsog/ProFileX.svg?style=flat&color=blue)
[![Open Source? Yes!](https://badgen.net/badge/Open%20Source%20%3F/Yes%21/blue?icon=github)](https://github.com/Naereen/badges/)


[![BSD 3-Clause License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

<!--
[![GPL license](https://img.shields.io/badge/License-GPL-blue.svg)](http://perso.crans.org/besson/LICENSE.html)
-->

[![Vim Powered](https://img.shields.io/badge/Vim-Powered-%2311AB00.svg?logo=vim&logoColor=white)](https://www.vim.org)
[![VS Code Powered](https://img.shields.io/badge/VS%20Code-Powered-%23007ACC.svg?logo=visualstudiocode&logoColor=white)](https://code.visualstudio.com/)

#

#### Compile

```
gcc `pkg-config --cflags gtk+-3.0` -o profilex src/main.c src/file_manager.c `pkg-config --libs gtk+-3.0`
```

#


#### Screenshots*

[![View Screenshots](https://img.shields.io/badge/View-Screenshots-yellow)](#)


<p align="center">
  <img src="./images/sshot-v0.0.6.png" alt="Screenshot Linux" width="400" height="350">
</p>

<sub>* This project is still under development. Future updates may include changes to the GUI, and screenshots may not accurately reflect the final design.</sub>

#

#### Installation
#### Via AUR using YAY

[![ProFileX](https://img.shields.io/badge/ProFileX-green)](#)

[![AUR](https://img.shields.io/aur/version/profilex)](https://aur.archlinux.org/packages/profilex)

<!-- 
[![AUR](https://img.shields.io/aur/version/profilex.svg)](https://aur.archlinux.org/packages/profilex)
-->

https://aur.archlinux.org/packages/profilex

ProFileX is available on AUR (Arch User Repository), and it can be installed using the `yay` package manager. Follow the steps below to install it:

1. Make sure you have `yay` installed. If not, you can install it with the following command:
   
   ```
   sudo pacman -S yay
   ```
   
   Once yay is installed, you can install by running the following command:
   
   ```
   yay -S profilex
   ```

This command will automatically fetch the package from AUR and handle the installation process for you.
Run it with the command opticpu.


#

#### Bash Installer 🚀 for Linux

[![Bash Installer Version](https://img.shields.io/badge/Bash%20Installer%20Version-Available-brightgreen)](#)

#### To Install it: 

To install it, simply run the installer script available [here](https://github.com/felipealfonsog/ProFileX/raw/main/installer.sh).

Or just Copy - Paste in your terminal and use -curl- to start downloading the installer:

   ```
   curl -O https://raw.githubusercontent.com/felipealfonsog/ProFileX/main/installer.sh
   ```

If you want to use -wget- just copy/paste this line:

   ```
   wget https://github.com/felipealfonsog/ProFileX/raw/main/installer.sh
   ```

   On macOS to download - wget - just install it with Homebrew:

   ```
   brew install wget
   ```


#### Important note when installing:

If you encounter issues executing the file in the terminal, like this message "-bash: ./installer.sh: Permission denied", follow these simple steps to fix it:

1. Open your terminal.
2. Navigate to the directory where the installer script is located using the `cd` command.
3. Run the following command to grant execute permission to the installer script:

   ```
   chmod +x installer.sh
   ```
   
4. Now you can run the installer without any problems.

   ```
   ./installer.sh
   ```
   NOTE: The script will ask for -sudo permissions-. Just simply type in Linux your -sudo- password.

Now type 'ProFileX' in the terminal and enjoy using it! 😊🚀


Feel free to reach out if you need any further assistance!

#### Updating with the script: 

If you want to update the program in your system, download the bash and re-run the script:

   ```
   ./installer.sh
   ```
Please note that if you encounter any issues or have suggestions, feel free to raise an issue on the [ProFileX repository](https://github.com/felipealfonsog/ProFileX/issues). Your feedback is invaluable!

Thank you for joining me on this journey, and I hope it brings value to your life and workflow. Let's continue making technology accessible and enjoyable for everyone!

#

#### 📝Important (Experimental Project)

[![Experimental Project](https://img.shields.io/badge/Project-Type%3A%20Experimental-blueviolet)](#)

This project is still in its experimental stage and may have limitations in terms of features and compatibility. Use at your own discretion.



#


#### 🌟 Contact the Creator and Engineer Behind This Project



👨‍💻 **Felipe Alfonso González**  
📧 Email: [f.alfonso@res-ear.ch](mailto:f.alfonso@res-ear.ch)  
🐦 x (Twitter): [@felipealfonsog](https://twitter.com/felipealfonsog)  
🔗 GitHub: [felipealfonsog](https://github.com/felipealfonsog)  
📄 License: BSD 3-Clause  


#

#### 🤝 Support and Contributions

If you find this project helpful and would like to support its development, there are several ways you can contribute:

- **Code Contributions**: If you're a developer, you can contribute by submitting pull requests with bug fixes, new features, or improvements. Feel free to fork the project (development branch) and create your own branch to work on.
- **Bug Reports and Feedback**: If you encounter any issues or have suggestions for improvement, please open an issue on the project's GitHub repository. Your feedback is valuable in making the project better.
- **Documentation**: Improving the documentation is always appreciated. If you find any gaps or have suggestions to enhance the project's documentation, please let me know.

[![Buy Me a Coffee](https://img.shields.io/badge/Buy%20Me%20a%20Coffee-%E2%98%95-FFDD00?style=flat-square&logo=buy-me-a-coffee&logoColor=black)](https://www.buymeacoffee.com/felipealfonsog)
[![PayPal](https://img.shields.io/badge/Donate%20with-PayPal-00457C?style=flat-square&logo=paypal&logoColor=white)](https://www.paypal.me/felipealfonsog)
[![GitHub Sponsors](https://img.shields.io/badge/Sponsor%20me%20on-GitHub-%23EA4AAA?style=flat-square&logo=github-sponsors&logoColor=white)](https://github.com/sponsors/felipealfonsog)

Your support and contributions are greatly appreciated! Thank you for your help in making this project better. If you need to mail me, this is the way: f.alfonso@res-ear.ch (I'm Felipe, the Computer Science Engineer behind this idea. Cheers!)


#### 📄 License

This project is licensed under the [BSD 3-Clause License](LICENSE). It will have some restrictions, ask about it.
