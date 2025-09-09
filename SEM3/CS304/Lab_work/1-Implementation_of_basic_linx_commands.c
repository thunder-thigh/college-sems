//Implementation of basic linux commands

//1. alias = Used to define aliases for commands within the bash shell.
//Syntax: alias <name>="<command>"
//this command can be used to define aliases/replacement of commands/phrases on shell. The <command> can be invoked using <name> in it's place

//2. bash = Start the Bourne-Again-SHell. This is a standard shell within many linux distributions.

//3. break = Keyword within BASH to break control flow of current block under execution.

//4. cat = Standard utility for concatenating files and printing to specified streams.
//Syntax: cat [OPTIONS] [FILE]
//Notable OPTIONS/Flags : [-A:Show all], [-n:number of lines to be printed]
//cat can be used to write to, and read from files. This is done via specifying the input and output streams. Both the input and output streams can be file paths or output/input streams of consoles.

//5. date = Simple tool used to print date and time.
//Output format: <day> <date> <month> <yyyy> <hh:mm:ss> <AM/PM> <Time Zone>

//6. dbus, dbus-send, dbus-daemon, dbus-run-session, dbus-monitor, dbus-cleanup-sockets
//These are all used to manage the dbus message bus system. Dbus provides inter-process communication infrastructure, it also helps coordinate process lifecycle. It provides a system daemon and a per-user-login-session-daemon (for general IPC)

//7. diff = compares files line by line
//Syntax: diff [OPTIONS] [FILES]

//8. dmesg = Requires root user privelage, helps read kernel level logs
//usage: [doas/sudo/su] dmesg

//9. echo = prints text to a specified stream/file.
//Syntax: echo "<text to be printed>" [>>/<<(pointing stream)] <stream>

//10. env = run a program in a modified environment
//Syntax: env [OPTION]... [-] [NAME=VALUE]....[COMMAND [ARG]...]
//This enables users to specify custom environment variables for execution of a program.
//This is very helpful for running different versions of same program without suffering from dependency issues, and also for making

//11. fgrep, grep, egrep, rgrep = print lines that match patterns
//Syntax: grep[OPTION....] PATTERNS [FILE]

//12. find = search for files in a directory hierarchy
//Syntax: find [OPTIONS...] [STARTING-POINT] EXPRESSION

//13. free = displays amount of free and used memory in the system.
//Syntax: free [OPTIONS]

//14. hexdump = displays files in hexadecimal/decimal/binary/octal/ascii formats
//Syntax: hexdump [OPTIONS] FILE

//15. history = displays shell history of commands run

//16. hostname = displays machine hostname

//17. id = prints real and effective groups andusers on the system with group IDs and user IDs,

//18.kill = kills specified process. May require elivated privelages depending on process to be killed.
//Syntax: kill PID

//19. kmod = manage kernel modules: list, load, unload, delete, disable, create, etc
//Syntax: kmod [OPTIONS] COMMAND [COMMAND OPTIONS]

//20
//lsattr = lists file attributes
//lsblk = lists block devices
//lscpu = lists CPU information like state, frequency, scaling governer etc
//lsfd = lists file descriptors
//lsinitframfs = list contents of initramfs
//lsipc = shows ips facilities employed on the system.
//lsirq = displayskernel interrupt information
//lslocks= lists locked services and processes.
//lslogins = lists active logins on machine.
//lsmem = lists memory used, available
//lsmod = lists kernel modules
//lsns = lists namespaces
//lsof = lists open files
//lspci = info about pci devices
//lspower = Lists data from power supply sensors
//lsusb = USB devices and status of the universal serial bus

//21. man = displays manual entry for a program if present
//Syntax: man [PROGRAM]

//22. mount = mount avaibale partions at a location within the filesystem
//Syntax: mount [DEVICE] MOUNT_POINT

//23. 
