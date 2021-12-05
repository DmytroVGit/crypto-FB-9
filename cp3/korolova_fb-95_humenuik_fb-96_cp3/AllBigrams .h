#include <string>
#include <fstream>
#include <streambuf>
#include<iostream>
#include<cmath>
#include <vector>
#include <locale>
#include <string>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <memory>
#include <map>
#include <unordered_map>
#include <iterator>
#include <regex>
#include <sstream>
#include <cmath>
#include <list>

using namespace std;

//�������� ���������� map
void StartMap(map<int, int>* pKey);
//������������ ��������� � ������� �������� � ������ � ����
void ArrangeNumbersInAscendingOrder(map<int, int>* pConstKey, map<int, int>* pKey);
//������������ ��������� � ������� �������� � ������ � ����
void ArrangeNumbersInDescendingOrder(map<int, int>* pConstKey, map<int, int>* pKey);
//������� �����
void OutKey(map<int, int> pKey);
//������ � ��� � ������������� �������� �� �����
void WriteTo(map<int, int>::iterator pIterator, map<int, int>* pMap, map<int, int>* pNSymphols);
//���������� ����� � ������� ��������
void ReWriting(map<int, int>::iterator pKeyForGame, map<int, int>* pKey, map<int, int>* pNSymphols);
//���������� ����� � ������� �����������
void ReWriting_Max(map<int, int>::iterator pKeyForGame, map<int, int>* pKey, map<int, int>* pNSymphols);
//����� �� �������� � ����
void MapFindValue(int pValue, map<int, int> pMap, int* pLocation);
//�������� �� ������������� �������� ����� ������������
void UsedMinElements(map<int, int> pUsedNumbers, map<int, int> pNSymphols, int* pMinElement);
//�������� �� ������������� ������� � ����� �������������
void UsedMaxElements(map<int, int> pUsedNumbers, map<int, int> pNSymphols, int* pMaxElement);
//����������� � map lNSymphols  
void WriteToNumberSympholsMap(map<int, int>::iterator pKeyForGame, map<int, int>::iterator pIteratorForMinElement, map<int, int>* pKey, int lMinElement, map<int, int>* pNSymphols);
//������ ���� �� ������ ������ 
void ChangerMap(map<int, int>* pUsedNumbers1Element, map<int, int>* pUsedNumbers2Element, map<int, int>* pUsedNumbers3Element, map<int, int>* pKey, map<int, int>::iterator pIteratorForCheckMap, int* pCounterFor1Element, int* pCounterFor2Element, int* pCounterFor3Element);
//��������� ���� ������ ��� � ��� ���� ��������
void GettingKeys(map<int, map<int, int>>* pAllKeys);