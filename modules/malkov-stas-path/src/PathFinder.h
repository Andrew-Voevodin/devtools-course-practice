#pragma once

/* �������� ��������.
� ������� SetGraph �������� ��������� �� ������� ���������� ����� vertice_num ������, 
����� ���� ����� ������������ � ��������� ������. */
class PathFinder {
    bool _IsInitialized = false;                            // ���� �������������
    int ** _Graph;                                          // ����
    int _Size;                                              // ������
    int _StartVertex;                                       // �������, �� ������� �������� ����������
    int* _Distance;                                         // ����������� ���������� �� ������
    bool* _Visited;                                         // ���������� �������
    void UpdateGraph();                                     // ��������� �����
    void Reset();                                           // ���������� ��� ������
public:
    PathFinder();
    PathFinder(int**, int, int = 0);
    void SetGraph(int**, int, int = 0);                     // ��������� ����� � ����������
    int GetDistance(int);                                   // ��������� ����������
};