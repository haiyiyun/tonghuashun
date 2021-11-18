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
