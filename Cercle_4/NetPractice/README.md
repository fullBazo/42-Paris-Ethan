*This project has been created as part of the 42 curriculum by ehuet.*

# NetPractice

## Description

NetPractice is a system administration and networking project from the 42 curriculum. The goal is to configure small-scale networks by solving 10 progressive levels, each presenting a broken network topology that must be fixed in order to make all hosts communicate correctly.

The project covers fundamental networking concepts such as IP addressing, subnet masks, routing tables, and the behavior of routers and switches. Each level requires understanding why a configuration fails and applying the correct values to restore connectivity.

## Instructions

### Running the training interface

Extract the project archive, then run the following command at the root of the repository:

```bash
./run.sh
```

This will open the NetPractice interface in your browser. You can then select a level and start configuring the network.

### Exporting your configuration

Once a level is solved, click the **"Get my config"** button on the interface to export your configuration. Place the exported files in your Git repository before submitting.

### Submission

Push your exported configuration files to your Git repository. Make sure the files are present at the root of the repository and that the repository is accessible before the evaluation.

## Resources

### Networking concepts studied

- **TCP/IP addressing** — understanding IPv4 addresses, their structure (network part vs host part), and how devices use them to communicate
- **Subnet masks & CIDR notation** — using masks like `255.255.255.252` or `/30` to divide a network into smaller subnets, calculating block sizes with the formula `256 - mask_octet`
- **Network address & broadcast** — identifying the first (network) and last (broadcast) address of a block, and why they cannot be assigned to hosts
- **Subnetting** — splitting an address space into multiple subnets, calculating usable IP ranges, and avoiding address conflicts between subnets
- **Default gateway** — configuring the gateway on each host so it knows where to send packets destined outside its local network
- **Routers** — understanding how a router forwards packets between different networks using its routing table, and how each router interface belongs to a separate subnet
- **Switches** — understanding that a switch operates at the MAC layer and connects hosts within the same network without requiring IP configuration
- **Routing tables** — filling in destination/gateway pairs, using `0.0.0.0/0` as a default route, and understanding how the first matching rule is applied
- **OSI model** — situating IP (layer 3) and switching (layer 2) in the broader model to understand what each device is responsible for

### References

- [RFC 791 — Internet Protocol](https://www.rfc-editor.org/rfc/rfc791)
- [Cisco — IP Addressing and Subnetting](https://www.cisco.com/c/en/us/support/docs/ip/routing-information-protocol-rip/13788-3.html)
- [Subnet calculator](https://www.subnet-calculator.com/)
- [ipcalc](https://jodies.de/ipcalc)

### AI usage

Claude (claude.ai) was used throughout this project as a learning companion. Specifically, it was used to:

- Understand and practice the binary AND operation used to compute network addresses from an IP and a subnet mask
- Learn the `256 - mask_octet` formula to quickly find block sizes and IP ranges without converting to binary
- Understand the role of the default gateway and how routing tables work (destination, gateway, default route)
- Debug incorrect configurations level by level, identifying issues such as IP conflicts, wrong subnets, missing or incorrect routes, and routing loops
- Understand the difference between what a switch and a router do at the network level
