# minitalk
This project has been created as part of 42 core cirriculm by iskaraag

## Instalation and Testing

```bash
git clone https://github.com/21isshak/minitalk.git
```
```bash  
cd minitalk
```
```bash  
make
```
```bash  
./server
```
In the same directory open a new terminal;
```bash
./client <PID_of_server> <message>
```
Example;
```bash  
./server 12345
```
On the other terminal;
```bash  
./client 12345 Hello 42!
```