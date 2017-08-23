// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ThostFtdcMdApi.h"
#include "MarketDataCollector.h"

using namespace std;
// UserApi����
CThostFtdcMdApi* pUserApi;

char  FRONT_ADDR[] = "tcp://180.168.146.187:10031";		// ǰ�õ�ַ
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// ���͹�˾����
TThostFtdcInvestorIDType INVESTOR_ID = "";			// ע�������������Լ���Ͷ���ߴ���
TThostFtdcPasswordType  PASSWORD = "";			// ע�������������Լ����û�����

char *ppInstrumentID[] = { "ni1701", "rb1701" };			// ���鶩���б�ע�⣬�����ԼID���ʱ�ģ�ע����ʱ����޸�
int iInstrumentID = 2;									// ���鶩������

														// ������
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
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();			// ����UserApi
	CThostFtdcMdSpi* pUserSpi = new MarketDataCollector();
	pUserApi->RegisterSpi(pUserSpi);						// ע���¼���
	pUserApi->RegisterFront(FRONT_ADDR);					// connect
	pUserApi->Init();

	pUserApi->Join();
	return 0;
}

