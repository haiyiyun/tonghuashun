#ifndef _EXPORTFUNCTION_H
#define _EXPORTFUNCTION_H
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
typedef void *PVOID;
#define  IN
#define  OUT
#define  WINAPI
#endif
#define FTDI_LOAD_FAILED                -102    // 加载DLL失败
#define MESSAGE_RESULT					"Result"			
#define MESSAGE_COMMAND					"Command"			
#define MESSAGE_MESSAGE					"Message"
#define MESSAGE_RETDATA					"RetData"
#define MESSAGE_RETCODE					"RetCode"
#define MESSAGE_LOGIN					"Login"		

#define HQRT_TYPE_REAL                  "Real"
#define HQRT_TYPE_L2TRACE               "L2Trace"

typedef int  (WINAPI *FT_CALLBACKResultsFunc) (IN  void* pUser, //函数调用时，调用者传入的参数指针
											  IN  int iQueryID, //函数调用时，返回给调用者，用于指明本次请求的ID
											  IN  wchar_t *pResultsBuff,//数据查询返回的结果，JSON格式
											  IN  int iBuffLength, //结果缓存区的长度
											  IN  int ErrorCode,//错误代码
											  IN  int Reserved//预留
											  ); 

typedef int (WINAPI *pfn_THS_iFinDLogin)(const char * szUserName, //用户名
											const char * szPassword//密码
											);

typedef int (WINAPI *pfn_THS_iFinDLogout)();

typedef int (WINAPI *pfn_THS_BasicData)(const char *Code, 
										   const char *indiname,
										   const char *params,char **ret);


typedef int (WINAPI *pfn_THS_DataPool)(const char* datapool,const char* inputparam,const char* outputparam,char **ret);
typedef int (WINAPI *pfn_THS_HighFrequenceSequence)( IN const char * THSCode, //同花顺代码
													   IN const char * jsonIndicator, //指标及指标需要的参数
													   IN const char * jsonParam,//函数需要的参数
													   IN const char * BeginTime, //请求的开始时间
													   IN const char * EndTime //请求的结束时间
													   ,char **ret);

typedef int (WINAPI *pfn_THS_RealtimeQuotes) (IN const char *THSCode, /*同花顺代码 */
												 IN const char *jsonIndicator,/*输入的指标字符串 */
												 IN const char *jsonParam,char **ret);

typedef int (WINAPI *pfn_THS_HistoryQuotes) (IN const char *THSCode, //同花顺代码
												IN const char * jsonIndicator, //指标及指标需要的参数
												IN const char * jsonParam,//函数需要的参数
												IN const char * BeginDate, //请求的开始日期
												IN const char * EndDate //请求的结束日
												,char **ret);

typedef int (WINAPI *pfn_THS_EDBQuery) (IN const char *Indiactor,  //指标
										   IN const char *BeginTime,
										   IN const char *EndTime
										   ,char **ret);

typedef int (WINAPI *pfn_THS_iwencai) (IN const char *doMain,  //指标
										IN const char *strType,
										char **ret);

typedef int (WINAPI *pfn_THS_WCQuery) (IN const char *doMain,  //指标
										IN const char *strType,
										char **ret);

typedef int (WINAPI *pfn_THS_DateSequence)(  IN const char *THSCode, //同花顺代码
											  IN const char * jsonIndicator, //指标及指标需要的参数
											  IN const char * jsonParam,//函数需要的参数
											  IN const char * BeginTime, //请求的开始时间
											  IN const char * EndTime //请求的结束时间
											  ,char **ret);

typedef int (WINAPI *pfn_THS_DataStatistics)(char** pRespData);
typedef int (WINAPI *pfn_THS_GetErrorInfo)(int ErrCode,char** ret);
typedef int (WINAPI *pfn_THS_DateQuery)(const char *Exchange,	//交易所名称
										   const char *Params,  //参数集
										   const char *StarDate,
										   const char *EndDate,
										   char** pRespData); //返回结果
typedef int (WINAPI *pfn_THS_Date_Query)(const char *Exchange,	//交易所名称
	                                       const char *Params,  //参数集
										   const char *StarDate,
										   const char *EndDate,
										   char** pRespData); //返回结果

typedef int (WINAPI *pfn_THS_DateOffset)(const char *Exchange,	//交易所名称
											const char *Params,  //参数集
											const char *pDate,
											char** pRespData); //返回结果
typedef int (WINAPI *pfn_THS_Date_Offset)(const char *Exchange,	//交易所名称
											const char *Params,  //参数集
											const char *pDate,
											char** pRespData); //返回结果

typedef int (WINAPI *pfn_THS_DateCount)(const char *Exchange,	//交易所名称
										   const char *Params,  //参数集
										   const char *StarDate,
										   const char *EndDate,
										   char** pRespData); //返回结果


typedef int (WINAPI *pfn_THS_AsyBasicData) (IN const char *THScode,
									  IN const char *IndiName, 
									  IN const char *ParamArr,
									  IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
									  IN void* pUser, //调用者的自定义参数
									  OUT int *piQueryID); //本次请求的ID，用于匹配返回结果

typedef int (WINAPI *pfn_THS_AsyDataPool) (IN const char *DataPoolName, //数据池名称
									 IN const char *jsonParamArr,  //参数集
									 IN const char *jsonFuncOptionalValueArr,//函数需要的参数
									 IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
									 IN void* pUser, //调用者的自定义参数
									 OUT int *piQueryID);//本次请求的ID，用于匹配返回结果

typedef int (WINAPI *pfn_THS_AsyDateSequence) ( IN const char *THSCode, //同花顺代码
										 IN const char * jsonIndicator, //指标及指标需要的参数
										 IN const char * jsonParam,//函数需要的参数
										 IN const char * BeginTime, //请求的开始时间
										 IN const char * EndTime, //请求的结束时间
										 IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
										 IN void* pUser, //调用者的自定义参数
										 OUT int *piQueryID);
typedef int (WINAPI *pfn_THS_AsyHighFrequenceSequence) (IN const char * THSCode, //同花顺代码
												  IN const char * jsonIndicator, //指标及指标需要的参数
												  IN const char * jsonParam,//函数需要的参数
												  IN const char * BeginTime, //请求的开始时间
												  IN const char * EndTime, //请求的结束时间
												  IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
												  IN void* pUser, //调用者的自定义参数
												  OUT int *piQueryID);

typedef int (WINAPI *pfn_THS_AsyRealtimeQuotes) (IN const char *THSCode,
										   IN const char *jsonIndicator,
										   IN const char *jsonParam, 
										   IN bool bOnlyOnce,/*true：只请求一次数据， false:实时推送数据 */ 
										   IN FT_CALLBACKResultsFunc CBResultsFunc,/*异步返回结果 */ 
										   IN void* pUser, /*调用者的自定义参数 */ 
										   OUT int *piQueryID);

typedef int (WINAPI *pfn_THS_AsyHistoryQuotes) ( IN const char *THSCode, //同花顺代码
										  IN const char * jsonIndicator, //指标及指标需要的参数
										  IN const char * jsonParam,//函数需要的参数
										  IN const char * BeginTime, //请求的开始时间
										  IN const char * EndTime, //请求的结束时间
										  IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
										  IN void* pUser, //调用者的自定义参数
										  OUT int *piQueryID);

typedef int (WINAPI *pfn_THS_Asyiwencai) (const char *query,  
										  const char *doMain,  //
										  FT_CALLBACKResultsFunc CBResultsFunc,//返回结果的回调函数
										  void* pUser,//用户传递的内存区
										  int  *piQueryID);

typedef int (WINAPI *pfn_THS_AsyWCQuery) (const char *query,
										  const char *doMain,  //
										  FT_CALLBACKResultsFunc CBResultsFunc,//返回结果的回调函数
										  void* pUser,//用户传递的内存区
										  int  *piQueryID);

typedef int (WINAPI *pfn_THS_AsyEDBQuery) (const char *Indiactor,  //指标
									const char *BeginTime,  //开始时间
									const char *EndTime,   //结束时间
									FT_CALLBACKResultsFunc CBResultsFunc,//返回结果的回调函数
									void* pUser,//用户传递的内存区
									int  *piQueryID);

typedef int (WINAPI *pfn_THS_QuotesPushing)(const char* THSCode, //同花顺代码
											  const char* jsonIndicator, //输入指标
											  const char* params,
											  int   Opreator,
											   FT_CALLBACKResultsFunc CBResultsFunc,//异步返回结果
											   void *pUser, //调用者的自定义参数
											   int *piQueryID);//本次请求的ID，用于匹配返回结果

typedef void (WINAPI *pfn_DeleteBuffer)(char **buffer);

typedef int (WINAPI *pfn_THS_DateSerial)( IN const char * THSCode, //同花顺代码
											IN const char * jsonIndicator, //指标及指标需要的参数
											IN const char * jsonParam,//函数需要的参数
											IN const char * globalParam,//函数需要的参数
											IN const char * BeginTime, //请求的开始时间
											IN const char * EndTime, //请求的结束时间
											OUT char** pRetData//返回结果
											);
typedef int (WINAPI *pfn_THS_AsyDateSerial)(IN const char * THSCode, //同花顺代码
											   IN const char * jsonIndicator, //指标及指标需要的参数
											   IN const char * jsonParam,//函数需要的参数
											   IN const char * globalParam,//函数需要的参数
											   IN const char * BeginTime, //请求的开始时间
											   IN const char * EndTime, //请求的结束时间
											   IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
											   IN void* pUser, //调用者的自定义参数
											   OUT int *piQueryID);

 void  THS_DeleteBuffer(char** buffer);

 int  THS_iFinDLogin(const char * szUserName, //用户名
										   const char * szPassword//密码
										   );

 int  THS_HistoryQuotes(IN const char *THSCode, //同花顺代码
											  IN const char * jsonIndicator, //指标及指标需要的参数
											  IN const char * jsonParam,//函数需要的参数
											  IN const char * BeginDate, //请求的开始日期
											  IN const char * EndDate , //请求的结束日期
											  OUT char** pRetData);//返回结果

////////////////////EDB
 int  THS_EDBQuery(	//
										 IN const char *Indiactor,  //指标
										 IN const char *BeginTime,
										 IN const char *EndTime,
										 OUT char **pRetData
										 );

int THS_QuotesPushing( const char* THScodes, const char* indicator, FT_CALLBACKResultsFunc callbackfunction, int* pQueryID);
int THS_UnQuotesPushing(const char* THScodes, const char* indicator,int* pQueryID);


////iwencai
int  THS_iwencai(	//
				  IN const char *doMain,  
				  IN const char *strType,
				  OUT char **pRetData
				  );

int  THS_WCQuery(	//
				  IN const char *doMain,  
				  IN const char *strType,
				  OUT char **pRetData
				  );

int  THS_Snapshot( IN const char * THSCode, //同花顺代码
				  IN const char * jsonIndicator, //指标及指标需要的参数
				  IN const char * jsonParam,//函数需要的参数
				  IN const char * BeginTime, //请求的开始时间
				  IN const char * EndTime, //请求的结束时间
				  OUT char** pRetData//返回结果
				  );
int  THS_AsySnapshot(IN const char * THSCode, //同花顺代码
					 IN const char * jsonIndicator, //指标及指标需要的参数
					 IN const char * jsonParam,//函数需要的参数
					 IN const char * BeginTime, //请求的开始时间
					 IN const char * EndTime, //请求的结束时间
					 IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
					 IN void* pUser, //调用者的自定义参数
					 OUT int *piQueryID);


 int  THS_BasicData(const char * thscode,const char * indicator,const char * params,char **ret);
 int  THS_DataPool(const char* datapool,const char* inputparam,const char* outputparam,char **ret);

  int  THS_DataStatistics(char** pRespData);
  int  THS_GetErrorInfo(int ErrCode,char** ret);
  int  THS_DateQuery(IN const char *Exchange,	//交易所名称
	 IN const char *Params,  //参数集
	 IN const char *StarDate,
	 IN const char *EndDate,
	 OUT char** pRespData); //返回结果

  int  THS_Date_Query(IN const char *Exchange,	//交易所名称
	  IN const char *Params,  //参数集
	  IN const char *StarDate,
	  IN const char *EndDate,
	  OUT char** pRespData); //返回结果

  int  THS_DateOffset(IN const char *Exchange,	//交易所名称
	 IN const char *Params,  //参数集
	 IN const char *pDate,
	 OUT char** pRespData); //返回结果

  int  THS_Date_Offset(IN const char *Exchange,	//交易所名称
	  IN const char *Params,  //参数集
	  IN const char *pDate,
	  OUT char** pRespData); //返回结果

  int  THS_DateCount(IN const char *Exchange,	//交易所名称
	 IN const char *Params,  //参数集
	 IN const char *StarDate,
	 IN const char *EndDate,
	 OUT char** pRespData); //返回结果
////////////////////实时行情
 int  THS_RealtimeQuotes(IN const char *THSCode, //同花顺代码
											   IN const char  *jsonIndicator, //输入的指标字符串
											   IN const char  *jsonParam, //输入的参数字符串
											   OUT char **pRespData
											   );

 int  THS_DateSequence(  IN const char *THSCode, //同花顺代码
											 IN const char * jsonIndicator, //指标及指标需要的参数
											 IN const char * jsonParam,//函数需要的参数
											 IN const char * BeginTime, //请求的开始时间
											 IN const char * EndTime, //请求的结束时间
											 OUT char** pRespData//返回结果
											 );
 int  THS_DateSerial(IN const char * THSCode, //同花顺代码
	 IN const char * jsonIndicator,//指标及指标需要的参数
	 IN const char * jsonParam,//函数需要的参数
	 IN const char * globalParam,//函数需要的参数
	 IN const char * BeginTime, //请求的开始时间
	 IN const char * EndTime, //请求的结束时间
	 OUT char** pRetData//返回结果
	 );

 int  THS_HighFrequenceSequence( IN const char * THSCode, //同花顺代码
													  IN const char * jsonIndicator, //指标及指标需要的参数
													  IN const char * jsonParam,//函数需要的参数
													  IN const char * BeginTime, //请求的开始时间
													  IN const char * EndTime, //请求的结束时间
													  OUT char** pRetData//返回结果
													  );


 int  THS_AsyRealtimeQuotes(IN const char *THSCode, //同花顺代码
												  IN const char  *jsonIndicator, //输入的指标字符串
												  IN const char  *jsonParam, //输入的参数字符串
												  IN bool bOnlyOnce,//true：只请求一次数据， false:实时推送数据
												  IN FT_CALLBACKResultsFunc CBResultsFunc,//异步返回结果
												  IN void* pUser, //调用者的自定义参数
												  OUT int *piQueryID);//本次请求的ID，用于匹配返回结果		


////c++interface
 int  THS_AsyBasicData(IN const char *THScode,
											 IN const char *IndiName, 
											 IN const char *ParamArr,
											 IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
											 IN void* pUser, //调用者的自定义参数
											 OUT int *piQueryID);//本次请求的ID，用于匹配返回结果


 int  THS_AsyDataPool(IN const char *DataPoolName, //数据池名称
											IN const char *jsonParamArr,  //参数集
											IN const char *jsonFuncOptionalValueArr,//函数需要的参数
											IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
											IN void* pUser, //调用者的自定义参数
											OUT int *piQueryID);//本次请求的ID，用于匹配返回结果

 int  THS_AsyDateSequence( IN const char *THSCode, //同花顺代码
												IN const char * jsonIndicator, //指标及指标需要的参数
												IN const char * jsonParam,//函数需要的参数
												IN const char * BeginTime, //请求的开始时间
												IN const char * EndTime, //请求的结束时间
												IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
												IN void* pUser, //调用者的自定义参数
												OUT int *piQueryID);//本次请求的ID，用于匹配返回结果

 int  THS_AsyHistoryQuotes( IN const char *THSCode, //同花顺代码
												 IN const char * jsonIndicator, //指标及指标需要的参数
												 IN const char * jsonParam,//函数需要的参数
												 IN const char * BeginTime, //请求的开始时间
												 IN const char * EndTime, //请求的结束时间
												 IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
												 IN void* pUser, //调用者的自定义参数
												 OUT int *piQueryID);

 int  THS_AsyEDBQuery(const char *Indiactor,  //指标
											const char *BeginTime,  //开始时间
											const char *EndTime,   //结束时间
											FT_CALLBACKResultsFunc CBResultsFunc,//返回结果的回调函数
											void* pUser,//用户传递的内存区
											int  *piQueryID);

 int  THS_Asyiwencai(const char *query,
	                                   const char *doMain,  //
	                                   FT_CALLBACKResultsFunc CBResultsFunc,//返回结果的回调函数
	                                   void* pUser,//用户传递的内存区
	                                   int  *piQueryID);

 int  THS_AsyWCQuery(const char *query,
	                                   const char *doMain,  //
	                                   FT_CALLBACKResultsFunc CBResultsFunc,//返回结果的回调函数
	                                   void* pUser,//用户传递的内存区
	                                   int  *piQueryID);



 int  THS_AsyHighFrequenceSequence(IN const char * THSCode, //同花顺代码
														 IN const char * jsonIndicator, //指标及指标需要的参数
														 IN const char * jsonParam,//函数需要的参数
														 IN const char * BeginTime, //请求的开始时间
														 IN const char * EndTime, //请求的结束时间
														 IN FT_CALLBACKResultsFunc CBResultsFunc, //返回结果的回调函数
														 IN void* pUser, //调用者的自定义参数
														 OUT int *piQueryID);//本次请求的ID，用于匹配返回结果

 int THS_iFinDLogout();

 bool InitialFunction(const char* path);

 #endif
