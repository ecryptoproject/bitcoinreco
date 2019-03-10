Sample init scripts and service configuration for bitcoinrecod
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/bitcoinrecod.service:    systemd service unit configuration
    contrib/init/bitcoinrecod.openrc:     OpenRC compatible SysV style init script
    contrib/init/bitcoinrecod.openrcconf: OpenRC conf.d file
    contrib/init/bitcoinrecod.conf:       Upstart service configuration file
    contrib/init/bitcoinrecod.init:       CentOS compatible SysV style init script

Service User
---------------------------------

All three Linux startup configurations assume the existence of a "bitcoinreco" user
and group.  They must be created before attempting to use these scripts.
The OS X configuration assumes bitcoinrecod will be set up for the current user.

Configuration
---------------------------------

At a bare minimum, bitcoinrecod requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, bitcoinrecod will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that bitcoinrecod and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If bitcoinrecod is run with the "-server" flag (set by default), and no rpcpassword is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but it's location can be overridden
with the option '-rpccookiefile'.

This allows for running bitcoinrecod without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings,
see `contrib/debian/examples/bitcoinreco.conf`.

Paths
---------------------------------

### Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/bitcoinrecod`  
Configuration file:  `/etc/bitcoinreco/bitcoinreco.conf`  
Data directory:      `/var/lib/bitcoinrecod`  
PID file:            `/var/run/bitcoinrecod/bitcoinrecod.pid` (OpenRC and Upstart) or `/var/lib/bitcoinrecod/bitcoinrecod.pid` (systemd)  
Lock file:           `/var/lock/subsys/bitcoinrecod` (CentOS)  

The configuration file, PID directory (if applicable) and data directory
should all be owned by the bitcoinreco user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
bitcoinreco user and group.  Access to bitcoinreco-cli and other bitcoinrecod rpc clients
can then be controlled by group membership.

### Mac OS X

Binary:              `/usr/local/bin/bitcoinrecod`  
Configuration file:  `~/Library/Application Support/Bitcoinreco/bitcoinreco.conf`  
Data directory:      `~/Library/Application Support/Bitcoinreco`  
Lock file:           `~/Library/Application Support/Bitcoinreco/.lock`  

Installing Service Configuration
-----------------------------------

### systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start bitcoinrecod` and to enable for system startup run
`systemctl enable bitcoinrecod`

NOTE: When installing for systemd in Debian/Ubuntu the .service file needs to be copied to the /lib/systemd/system directory instead.

### OpenRC

Rename bitcoinrecod.openrc to bitcoinrecod and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/bitcoinrecod start` and configure it to run on startup with
`rc-update add bitcoinrecod`

### Upstart (for Debian/Ubuntu based distributions)

Upstart is the default init system for Debian/Ubuntu versions older than 15.04. If you are using version 15.04 or newer and haven't manually configured upstart you should follow the systemd instructions instead.

Drop bitcoinrecod.conf in /etc/init.  Test by running `service bitcoinrecod start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

### CentOS

Copy bitcoinrecod.init to /etc/init.d/bitcoinrecod. Test by running `service bitcoinrecod start`.

Using this script, you can adjust the path and flags to the bitcoinrecod program by
setting the BITCOINRECOD and FLAGS environment variables in the file
/etc/sysconfig/bitcoinrecod. You can also use the DAEMONOPTS environment variable here.

### Mac OS X

Copy org.bitcoinreco.bitcoinrecod.plist into ~/Library/LaunchAgents. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.bitcoinreco.bitcoinrecod.plist`.

This Launch Agent will cause bitcoinrecod to start whenever the user logs in.

NOTE: This approach is intended for those wanting to run bitcoinrecod as the current user.
You will need to modify org.bitcoinreco.bitcoinrecod.plist if you intend to use it as a
Launch Daemon with a dedicated bitcoinreco user.

Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
