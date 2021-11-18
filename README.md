## 下载最新的库

    1. 访问http://quantapi.10jqka.com.cn/?page=downCenter
    2. 下载linux版本

## 整理目录并设置库环境变量

    例如：库下载保存并解压到：/usr/include/tonghuashun目录下
    1. 只留下bin64目录，其他目录和文件删除
    2. bin64目录下只留下
        ├── Tool
        ├── etc
        ├── quote
        ├── libFTDataInterface.so
        └── libShellExport.so
    3. 设置环境变量
        1. 设置临时环境变量
            export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/include/tonghuashun/bin64
        2. 设置固定环境变量
            echo "LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/include/tonghuashun/bin64" >> /etc/bash.bashrc
        3. 是环境变量生效（二选一）
           1. 重新进入终端
           2. source /etc/bash.bashrc

## 注意事项

编译运行时如果出现：

    /usr/bin/ld: warning: libidn.so.11, needed by ...

请按照对应库，例如ubuntu下：

    1. 查找对应库
        apt search libidn
    2. 下载按照对应库
        apt install libidn11-dev

## 使用方式

    1. 项目导入
        import . "github.com/haiyiyun/tonghuashun"
    2. 参见example目录sample.go

## 示例代码

```golang
package main

import (
	"fmt"

	. "github.com/haiyiyun/tonghuashun"
)

func main() {
	username := "username"
	password := "password"

	retn := THS_iFinDLogin(username, password)
	fmt.Println(retn)

	retn, retData := THS_HighFrequenceSequence("600000.SH",
		"open;high;low;close",
		"CPS:no,baseDate:1900-01-01,MaxPoints:50000,Fill:Previous,Interval:1",
		"2019-01-04 09:15:00",
		"2019-01-04 15:15:00")

	fmt.Println(retn)
	fmt.Println(retData)

	retn, retData = THS_RealtimeQuotes("300033.SZ",
		"open;high;low;latest;changeRatio;amount;volume;bid1;ask1",
		"pricetype:1")

	fmt.Println(retn)
	fmt.Println(retData)
}
```