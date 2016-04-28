#ifndef PATH_FINDER
#define PATH_FINDER

#define PATH_NOT_EXISTS -1      // GetDistance ���������� ��� ���������� ���� � �����

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
    void CheckVetricesWithoutPath();                        // �������� ������ ��� ����
public:
    PathFinder();
    PathFinder(int**, int, int = 0);
    void SetGraph(int**, int, int = 0);                     // ��������� ����� � ����������
    int GetDistance(int);                                   // ��������� ����������
    int* GetDistances();                                    // ��������� ���� ����������
};

#endif