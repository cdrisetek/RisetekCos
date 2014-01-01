/*
 * btools cli
 */
#include <pkgconf/system.h>
#include <pkgconf/produce.h>
#include CYGBLD_HAL_PLATFORM_H
#ifdef	CYGPKG_COMMAND_LINE_INTERFACE
#include <cyg/cli/cli.h>
#include <cyg/cli/cli_thread.h>
#include <stdlib.h>
#include <cyg/fileio/fileio.h>
#include <unistd.h>

#include <btools/application.h>
//#include <application/produce.h>

#ifdef	CYGPKG_LIBARCHIVE
#include <lib/libarchive.h>
static int cmd_btools_install(struct cli_def *cli, char *command, char *argv[], int argc)
{
	extract(argv[0], 1, 0);
	return CLI_OK;
}
#endif

static void btools_init_network(struct cli_def *cli)
{
	cli_print(cli,"bTools should init networks:");
	cli_print(cli,"Set IP address to %s and start tftp service.", DEFAULT_IP_ADDRESS);

	cli_sys_execute("interface eth 0", 0, MODE_CONFIG);
	cli_sys_execute("ip address "DEFAULT_IP_ADDRESS" 255.255.255.0", 0, MODE_CONFIG_INT_ETH);


	cli_sys_execute("tftp server", 0, MODE_CONFIG);
}

static void btools_init_fs(struct cli_def *cli)
{
	cli_print(cli, "bTools should init file system:");
	umount("/");
	mount(CYGOPT_ROOT_FILE_SYSTEM_NAME,"/","yaffs");
	chdir("/");
	cli_print(cli, "\r\nFile system init ok!\r\n");
}


static int cmd_btools_init_all_reformat(struct cli_def *cli, char *command, char *argv[], int argc)
{
	umount("/");

	cli_print(cli, "bTools should init system, and erase all datas on this device!");

	char ctl;

	// drain buffered char.
	read(cli->fd, &ctl, 1);
	cli_print(cli, "\r\nProceed with nandflash reformat? [y|Y to confirm]\r\n");

	read(cli->fd, &ctl, 1);
	if (ctl == 'y' || ctl == 'Y')
	{
		cli_print(cli, "formatting nandflash......");
		cli_sys_execute("flash format " CYGOPT_ROOT_FILE_SYSTEM_NAME, 0, MODE_EXEC);
		cli_print(cli, "nandflash formated.\r\n");
		btools_init_fs(cli);
#ifdef	CYGPKG_NET
		btools_init_network(cli);
#endif
	}
	return CLI_OK;
}


static int cmd_btools_init_all(struct cli_def *cli, char *command, char *argv[], int argc)
{
	btools_init_fs(cli);
#ifdef	CYGPKG_NET
	btools_init_network(cli);
#endif
	return CLI_OK;
}

#ifdef	CYGPKG_NET
static int cmd_btools_init_network(struct cli_def *cli, char *command, char *argv[], int argc)
{

	btools_init_network(cli);

	return CLI_OK;
}
#endif

static int cmd_btools_init_fs(struct cli_def *cli, char *command, char *argv[], int argc)
{
	btools_init_fs(cli);
	return CLI_OK;
}

static int produce_btools_register(struct cli_def *cli)
{
	struct cli_command *temp, *all;
	temp = cli_register_command(cli, NULL, "btools", NULL, PRIVILEGE_PRIVILEGED, MODE_EXEC, "btools");
#ifdef	CYGPKG_LIBARCHIVE
	struct cli_command *temp1 = cli_register_command(cli, temp, "extract", NULL, PRIVILEGE_PRIVILEGED, MODE_EXEC, "extract tar.gz file.");
    cli_register_word_command(cli, temp1, cmd_btools_install , PRIVILEGE_PRIVILEGED, MODE_EXEC, "sources name");
#endif
	temp = cli_register_command(cli, temp, "init", NULL, PRIVILEGE_PRIVILEGED, MODE_EXEC, "init");

	all = cli_register_command(cli, temp, "all", cmd_btools_init_all, PRIVILEGE_PRIVILEGED, MODE_EXEC, "all include file system and networks");
	cli_register_command(cli, all, "reformat", cmd_btools_init_all_reformat, PRIVILEGE_PRIVILEGED, MODE_EXEC, "format nandflash before init");
#ifdef	CYGPKG_NET
	cli_register_command(cli, temp, "netwrok", cmd_btools_init_network, PRIVILEGE_PRIVILEGED, MODE_EXEC, "networks");
#endif
	cli_register_command(cli, temp, "fs", cmd_btools_init_fs, PRIVILEGE_PRIVILEGED, MODE_EXEC, "file system");

	return 0x0;
}

CLI_COMMANDS_REGISTER(produce_btools,produce_btools_register);
#endif	// CYGPKG_COMMAND_LINE_INTERFACE
