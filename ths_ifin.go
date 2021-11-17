package ths

// #cgo CFLAGS: -I cpp/include
// #cgo LDFLAGS: -L cpp/lib -lShellExport
// #include <stdlib.h>
// #include <stdbool.h>
// #include <ExportFunction.h>
import "C"
import (
	"unsafe"
)

//登录
func THS_iFinDLogin(username, password string) int {
	cusername := C.CString(username)
	cpassword := C.CString(password)
	defer C.free(unsafe.Pointer(cusername))
	defer C.free(unsafe.Pointer(cpassword))

	retn := C.THS_iFinDLogin(cusername, cpassword)

	return int(retn)
}

//登出
func THS_iFinDLogout(thscode, jsonIndicator, jsonParam, beginTime, endTime string) int {
	retn := C.THS_iFinDLogout()
	return int(retn)
}

//高频序列
func THS_HighFrequenceSequence(thscode, jsonIndicator, jsonParam, beginTime, endTime string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cthscode := C.CString(thscode)
	defer C.free(unsafe.Pointer(cthscode))
	cjsonIndicator := C.CString(jsonIndicator)
	defer C.free(unsafe.Pointer(cjsonIndicator))
	cjsonParam := C.CString(jsonParam)
	defer C.free(unsafe.Pointer(cjsonParam))
	cbeginTime := C.CString(beginTime)
	defer C.free(unsafe.Pointer(cbeginTime))
	cendTime := C.CString(endTime)
	defer C.free(unsafe.Pointer(cendTime))

	retn := C.THS_HighFrequenceSequence(cthscode, cjsonIndicator, cjsonParam, cbeginTime, cendTime, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

//实时行情
func THS_RealtimeQuotes(thscode, jsonIndicator, jsonParam string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cthscode := C.CString(thscode)
	defer C.free(unsafe.Pointer(cthscode))
	cjsonIndicator := C.CString(jsonIndicator)
	defer C.free(unsafe.Pointer(cjsonIndicator))
	cjsonParam := C.CString(jsonParam)
	defer C.free(unsafe.Pointer(cjsonParam))

	retn := C.THS_RealtimeQuotes(cthscode, cjsonIndicator, cjsonParam, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

//基础数据
func THS_BasicData(thscode, indicator, params string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cthscode := C.CString(thscode)
	defer C.free(unsafe.Pointer(cthscode))
	cindicator := C.CString(indicator)
	defer C.free(unsafe.Pointer(cindicator))
	cparams := C.CString(params)
	defer C.free(unsafe.Pointer(cparams))

	retn := C.THS_BasicData(cthscode, cindicator, cparams, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

//数据池
func THS_DataPool(datapool, inputparam, outputparam string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cdatapool := C.CString(datapool)
	defer C.free(unsafe.Pointer(cdatapool))
	cinputparam := C.CString(inputparam)
	defer C.free(unsafe.Pointer(cinputparam))
	coutputparam := C.CString(outputparam)
	defer C.free(unsafe.Pointer(coutputparam))

	retn := C.THS_DataPool(cdatapool, cinputparam, coutputparam, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

func THS_DateSequence(thscode, jsonIndicator, jsonParam, beginTime, endTime string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cthscode := C.CString(thscode)
	defer C.free(unsafe.Pointer(cthscode))
	cjsonIndicator := C.CString(jsonIndicator)
	defer C.free(unsafe.Pointer(cjsonIndicator))
	cjsonParam := C.CString(jsonParam)
	defer C.free(unsafe.Pointer(cjsonParam))
	cbeginTime := C.CString(beginTime)
	defer C.free(unsafe.Pointer(cbeginTime))
	cendTime := C.CString(endTime)
	defer C.free(unsafe.Pointer(cendTime))

	retn := C.THS_DateSequence(cthscode, cjsonIndicator, cjsonParam, cbeginTime, cendTime, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

//EDB 数据
func THS_EDBQuery(indiactor, beginTime, endTime string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cindiactor := C.CString(indiactor)
	defer C.free(unsafe.Pointer(cindiactor))
	cbeginTime := C.CString(beginTime)
	defer C.free(unsafe.Pointer(cbeginTime))
	cendTime := C.CString(endTime)
	defer C.free(unsafe.Pointer(cendTime))

	retn := C.THS_EDBQuery(cindiactor, cbeginTime, cendTime, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

//历史行情
func THS_HistoryQuotes(thscode, jsonIndicator, jsonParam, beginTime, endTime string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cthscode := C.CString(thscode)
	defer C.free(unsafe.Pointer(cthscode))
	cjsonIndicator := C.CString(jsonIndicator)
	defer C.free(unsafe.Pointer(cjsonIndicator))
	cjsonParam := C.CString(jsonParam)
	defer C.free(unsafe.Pointer(cjsonParam))
	cbeginTime := C.CString(beginTime)
	defer C.free(unsafe.Pointer(cbeginTime))
	cendTime := C.CString(endTime)
	defer C.free(unsafe.Pointer(cendTime))

	retn := C.THS_HistoryQuotes(cthscode, cjsonIndicator, cjsonParam, cbeginTime, cendTime, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

//数据量统计函数
func THS_DataStatistics() (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	retn := C.THS_DataStatistics(&pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

func THS_GetErrorInfo(errCode int) string {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	C.THS_GetErrorInfo(C.int(errCode), &pRetData)
	retData := C.GoString(pRetData)

	return retData
}

//日期查询
func THS_DateQuery(exchange, param, startDate, endDate string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cexchange := C.CString(exchange)
	defer C.free(unsafe.Pointer(cexchange))
	cparam := C.CString(param)
	defer C.free(unsafe.Pointer(cparam))
	cstartDate := C.CString(startDate)
	defer C.free(unsafe.Pointer(cstartDate))
	cendDate := C.CString(endDate)
	defer C.free(unsafe.Pointer(cendDate))

	retn := C.THS_DateQuery(cexchange, cparam, cstartDate, cendDate, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

//日期偏移
func THS_DateOffset(exchange, param, date string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cexchange := C.CString(exchange)
	defer C.free(unsafe.Pointer(cexchange))
	cparam := C.CString(param)
	defer C.free(unsafe.Pointer(cparam))
	cdate := C.CString(date)
	defer C.free(unsafe.Pointer(cdate))

	retn := C.THS_DateOffset(cexchange, cparam, cdate, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

//日期统计
func THS_DateCount(exchange, param, startDate, endDate string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cexchange := C.CString(exchange)
	defer C.free(unsafe.Pointer(cexchange))
	cparam := C.CString(param)
	defer C.free(unsafe.Pointer(cparam))
	cstartDate := C.CString(startDate)
	defer C.free(unsafe.Pointer(cstartDate))
	cendDate := C.CString(endDate)
	defer C.free(unsafe.Pointer(cendDate))

	retn := C.THS_DateCount(cexchange, cparam, cstartDate, cendDate, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}

// //日内快照
// func THS_Snapshot(thscode, jsonIndicator, jsonParam, beginTime, endTime string) (int, string) {
// 	var pRetData *C.char
// 	defer C.free(unsafe.Pointer(pRetData))

// 	cthscode := C.CString(thscode)
// 	defer C.free(unsafe.Pointer(cthscode))
// 	cjsonIndicator := C.CString(jsonIndicator)
// 	defer C.free(unsafe.Pointer(cjsonIndicator))
// 	cjsonParam := C.CString(jsonParam)
// 	defer C.free(unsafe.Pointer(cjsonParam))
// 	cbeginTime := C.CString(beginTime)
// 	defer C.free(unsafe.Pointer(cbeginTime))
// 	cendTime := C.CString(endTime)
// 	defer C.free(unsafe.Pointer(cendTime))

// 	retn := C.THS_Snapshot(cthscode, cjsonIndicator, cjsonParam, cbeginTime, cendTime, &pRetData)
// 	retData := C.GoString(pRetData)

// 	return int(retn), retData
// }

// //智能选股
// func THS_iwencai(searchString, parameter string) (int, string) {
// 	var pRetData *C.char
// 	defer C.free(unsafe.Pointer(pRetData))

// 	csearchString := C.CString(searchString)
// 	defer C.free(unsafe.Pointer(csearchString))
// 	cparameter := C.CString(parameter)
// 	defer C.free(unsafe.Pointer(cparameter))

// 	retn := C.THS_iwencai(csearchString, cparameter, &pRetData)
// 	retData := C.GoString(pRetData)

// 	return int(retn), retData
// }

// //日期序列
// func THS_DateSerial(thscode, jsonIndicator, jsonParam, globalParam, beginTime, endTime string) (int, string) {
// 	var pRetData *C.char
// 	defer C.free(unsafe.Pointer(pRetData))

// 	cthscode := C.CString(thscode)
// 	defer C.free(unsafe.Pointer(cthscode))
// 	cjsonIndicator := C.CString(jsonIndicator)
// 	defer C.free(unsafe.Pointer(cjsonIndicator))
// 	cjsonParam := C.CString(jsonParam)
// 	defer C.free(unsafe.Pointer(cjsonParam))
// 	cglobalParam := C.CString(globalParam)
// 	defer C.free(unsafe.Pointer(cglobalParam))
// 	cbeginTime := C.CString(beginTime)
// 	defer C.free(unsafe.Pointer(cbeginTime))
// 	cendTime := C.CString(endTime)
// 	defer C.free(unsafe.Pointer(cendTime))

// 	retn := C.THS_DateSerial(cthscode, cjsonIndicator, cjsonParam, cglobalParam, cbeginTime, cendTime, &pRetData)
// 	retData := C.GoString(pRetData)

// 	return int(retn), retData
// }

// //形态预测
// func THS_Special_ShapePredict(thscode, param, beginTime, endTime string) (int, string) {
// 	var pRetData *C.char
// 	defer C.free(unsafe.Pointer(pRetData))

// 	cthscode := C.CString(thscode)
// 	defer C.free(unsafe.Pointer(cthscode))
// 	cparam := C.CString(param)
// 	defer C.free(unsafe.Pointer(cparam))
// 	cbeginTime := C.CString(beginTime)
// 	defer C.free(unsafe.Pointer(cbeginTime))
// 	cendTime := C.CString(endTime)
// 	defer C.free(unsafe.Pointer(cendTime))

// 	retn := C.THS_Special_ShapePredict(cthscode, cparam, cbeginTime, cendTime, &pRetData)
// 	retData := C.GoString(pRetData)

// 	return int(retn), retData
// }

// //期股联动
// func THS_Special_StockLink(thscode, Param string) (int, string) {
// 	var pRetData *C.char
// 	defer C.free(unsafe.Pointer(pRetData))

// 	cthscode := C.CString(thscode)
// 	defer C.free(unsafe.Pointer(cthscode))
// 	cParam := C.CString(Param)
// 	defer C.free(unsafe.Pointer(cParam))

// 	retn := C.THS_Special_StockLink(cthscode, cParam, &pRetData)
// 	retData := C.GoString(pRetData)

// 	return int(retn), retData
// }

//基金实时估值
func THS_realTimeValuation(thscode, inputparam, outputparam string) (int, string) {
	var pRetData *C.char
	defer C.free(unsafe.Pointer(pRetData))

	cthscode := C.CString(thscode)
	defer C.free(unsafe.Pointer(cthscode))
	cinputparam := C.CString(inputparam)
	defer C.free(unsafe.Pointer(cinputparam))
	coutputparam := C.CString(outputparam)
	defer C.free(unsafe.Pointer(coutputparam))

	retn := C.THS_realTimeValuation(cthscode, cinputparam, coutputparam, &pRetData)
	retData := C.GoString(pRetData)

	return int(retn), retData
}
