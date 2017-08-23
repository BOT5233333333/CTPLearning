// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ThostFtdcMdApi.h"
#include "MarketDataCollector.h"

using namespace std;
// UserApi对象
CThostFtdcMdApi* pUserApi;

char  FRONT_ADDR[] = "tcp://180.168.146.187:10031";		// 前置地址
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "";			// 注意这里输入你自己的投资者代码
TThostFtdcPasswordType  PASSWORD = "";			// 注意这里输入你自己的用户密码

char *ppInstrumentID[] = { "ni1701", "rb1701" };			// 行情订阅列表，注意，这个合约ID会过时的，注意与时俱进修改
int iInstrumentID = 2;									// 行情订阅数量

														// 请求编号
int iRequestID = 0;

int main()
{
	/*const char* mdflowpath = "D:\\test.con";
	char* mdfront = "tcp://127.0.0.1:17001";
	cout << "mdflowpath is:" + (string)mdflowpath << endl;
	CThostFtdcMdApi *api = CThostFtdcMdApi::CreateFtdcMdApi(mdflowpath, true);
	MarketDataCollector mcCollector(api);
	api->RegisterSpi(&mcCollector);
	api->RegisterFront(mdfront);
	api->Init();
	api->Join();*/
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();			// 创建UserApi
	CThostFtdcMdSpi* pUserSpi = new MarketDataCollector();
	pUserApi->RegisterSpi(pUserSpi);						// 注册事件类
	pUserApi->RegisterFront(FRONT_ADDR);					// connect
	pUserApi->Init();

	pUserApi->Join();
	return 0;
}

