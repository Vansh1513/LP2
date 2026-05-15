/*
server {
    listen 80;
    server_name 13.232.252.114;

    # Frontend (Static Files)
    location / {
        root /home/ubuntu/blog-app/client/dist;
        index index.html;
        try_files $uri $uri/ /index.html;
    }

    # Backend API (Proxy)
    location /api {
        proxy_pass http://localhost:5000;

        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';
        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
    }
}
*/

//MONGO_URI=mongodb+srv://user2000:user321123@cluster0.tb3du.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0

//scp -i vpc.pem vpc.pem ubuntu@13.xx.xx.xx:/home/ubuntu/ (public ip of vm1 on terminal)

//scp -i vpc.pem vansh.txt ubuntu@13.xx.xx.xx:/home/ubuntu/  (pvt ip of vm2 on vm1)






















/*
Step 2 — Create VPC

Created a custom VPC with:

Property	Value
VPC Name	SecureFileVPC
CIDR Block	10.0.0.0/16

Purpose:

Isolated private network for EC2 communication
Step 3 — Create Subnet

Created subnet inside VPC:

Property	Value
Subnet Name	PublicSubnet
CIDR Block	10.0.3.0/24

Purpose:

Allocate IP addresses for EC2 instances
Step 4 — Create Internet Gateway

Created Internet Gateway:

Property	Value
Name	SecureIGW

Attached Internet Gateway to:

SecureFileVPC

Purpose:

Enable internet connectivity
Step 5 — Configure Route Table

Created Route Table:

Property	Value
Name	SecureFileVPC-rtb-public

Added Route:

Destination	Target
0.0.0.0/0	Internet Gateway

Associated subnet:

10.0.3.0/24

Purpose:

Route internet traffic correctly
Step 6 — Create Security Group

Created Security Group:

Property	Value
Name	SecureFileSG

Added inbound rules:

Type	Port	Source
SSH	22	My IP
SSH	22	SecureFileSG

Purpose:

Allow secure SSH communication
Allow internal VM-to-VM communication
Step 7 — Launch EC2 Instances

Created two Ubuntu EC2 instances.

VM1
Property	Value
Name	VM1
Instance Type	t2.micro
OS	Ubuntu
VM2
Property	Value
Name	VM2
Instance Type	t2.micro
OS	Ubuntu

Both instances:

placed inside SecureFileVPC
connected to PublicSubnet
assigned public IPs
attached to SecureFileSG
Step 8 — Configure PEM Key

Downloaded key pair:

vpc.pem

Applied permissions on Mac:

chmod 400 vpc.pem

Purpose:

Secure SSH authentication
Step 9 — Connect to VM1 Using SSH

SSH command:

ssh -i "vpc.pem" ubuntu@13.xx.xx.xx

Successfully connected to VM1.

Purpose:

Secure remote administration
Step 10 — Copy PEM Key to VM1

Transferred key file to VM1 using SCP:

scp -i vpc.pem vpc.pem ubuntu@13.xx.xx.xx:/home/ubuntu/

Purpose:

Enable VM1 to securely connect to VM2
Step 11 — Create Secure File

Inside VM1:

nano securefile.txt

Added content:

Hello from VM1
Secure File Sharing Successful
Step 12 — Transfer File Securely

Used SCP from VM1 to VM2:

scp -i vpc.pem securefile.txt ubuntu@10.0.3.xxx:/home/ubuntu/

Purpose:

Secure encrypted file transfer inside VPC
Step 13 — Verify File in VM2

Connected to VM2 using SSH:

ssh -i "vpc.pem" ubuntu@13.xx.xx.xx

Verified transferred file:

ls
cat securefile.txt

Output:

Hello from VM1
Secure File Sharing Successful
Step 14 — Apply File Permissions

Restricted file access:

chmod 600 securefile.txt

Verified permissions:

ls -l

Purpose:

Only owner can read/write file
Security Features Implemented
Feature	Purpose
SSH	Secure encrypted remote login
SCP	Secure encrypted file transfer
Security Groups	Firewall protection
Private IP Communication	Internal AWS networking
Linux Permissions	File access control
PEM Authentication	Key-based authentication

*/