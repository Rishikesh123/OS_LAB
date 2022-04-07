# OS LAB ASSIGNMENT 4

GROUP-35

Creators:
  * SAURABH BARANWAL, Roll no: 180101072
  * MOHAN KUMAR, Roll no: 180101042
  * RAHUL KRISHNA, Roll no: 180123035
  * PANKAJ KUMAR, Roll no: 180123031
  
WE WILL BE PERFORMING OUR ASSIGNMENT FOR TWO FEATURES: DEDUPLICATION AND COMPRESSION ON TWO DIFFERENT CONFIGURATIONS OF ZFS FILE SYSTEM (ON AND OFF)

The first tep is to install ZFS. That can be done through this site: https://ubuntu.com/tutorials/setup-zfs-storage-pool#3-creating-a-zfs-pool

The installation procedure has also been described in the report.

Note that we will assume the name of our ZFS pool to be new-pool (as evident from above installation process). You can very well have your own name of ZSF pool created, but do make necessary changes whenever required. It is preferrable if you name it new-pool too. 

### Running the Code

Now, copy both the files zfs_dedup and zfs_compression inside the folder vdbench

Before running the code, a small change needs to be made in each of the files zfs_dedup and zfs_compression. The anchor directory location needs to be changed in accordance with the corresponding location at which your ZFS pool is mounted at. The location can be founded by typing following in Terminal:

```bash
$ zfs list 
```

The above command on terminal will list the ZFS pool and the value corresponding to column 'MOUNTPOINT' should be entered as the anchor=*mountpoint* in the files zfs_dedup and zfs_compression

### FEATURE-1 DEDUPLICATION

To turn ZFS deduplication on, write command:

```bash
$ sudo zfs set dedup=on new-pool
```
Now, run the command to run workload zfs_dedup on vdbench. The following command:

```bash
$ sudo ./vdbench -f zfs_dedup
```
Now, to view the total allocation size, we can view the column field ALLOC value when we run the following command:

```bash
$ zpool list
```

The same two commands can be run to obtain the value, after turning deduplication off using following command:

```bash
$ sudo zfs set dedup=off new-pool
```

### FEATURE-2 COMPRESSION

To turn ZFS compression on using lz4, write command:

```bash
$ sudo zfs set compression=lz4 new-pool
```

To turn ZFS compression off, write command:

```bash
$ sudo zfs set compression=off new-pool
```

For both the above configurations, we run the workload zfs_compression using following command:

```bash
$ sudo ./vdbench -f zfs_compression 
```

Now, to view the total allocation size, we can view the column field ALLOC value when we run the following command:

```bash
$ zpool list
```

Also, to view the compressionratio corresponding to each case; we run the following command

```bash
$ ​zfs get-compressratio new-pool
```
______________________________________________________________________________

NOTE: The folder observation contains the output of all the 4 cases. You can read file summary.html to view overall statistics for each case.

output_dedup_on  : Output files of vdbench when deduplication is ON
output_dedup_off  : Output files of vdbench when deduplication is ON
output_comp_lz4  : Output files of vdbench when compression is turned OFF using lz4 algorithm
output_comp_off : Output files of vdbench when compression is OFF





