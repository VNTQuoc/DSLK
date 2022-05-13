#include <iostream>

using namespace std;

struct Node
{
    int infor;
    Node* next;
};
struct List
{
    Node* Head;
    Node* Tail;
};
void CreateList(List& l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
Node* CreateNode(int x)
{
    Node* p = new Node;
    p->infor = x;
    p->next = NULL;
    return p;
}
void AddHead(List& l, Node* p)
{
    if (l.Head == NULL)
        l.Head = l.Tail = p;
    else
    {
        p->next = l.Head;
        l.Head = p;
    }
}
void AddTail(List& l, Node* p)
{
    if (l.Head == NULL)
        l.Head = l.Tail = p;
    else
    {
        l.Tail->next = p;
        l.Tail = p;
    }
}
void AddAfterQ(List& l, Node* p, Node* q)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
    }
    else l.Tail = p;
}
void InputList(List& l)
{
    int n;
    cout << "How many elements you want in the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Type value number " << i + 1 << ": ";
        cin >> x;
        cout << endl;
        Node* p = CreateNode(x);
        AddHead(l, p);
    }
}
//Duyet danh sach
void PrintList(List l)
{
    cout << "The list: ";
    for (Node* p = l.Head;p != NULL;p = p->next)
        cout << p->infor << "     ";
}
bool SNT(int a)
{
    if (a < 2)
        return false;
    else
    {
        for (int i = 2; i < a; i++)
            if (a % i == 0)
                return false;
        return true;
    }
}

void SapXepTangDan(List& l)
{
    for (Node* p = l.Head; p != l.Tail; p = p->next)
        for (Node* q = p; q != NULL; q = q->next)
            if (q->infor < p->infor)
            {
                int temp = p->infor;
                p->infor = q->infor;
                q->infor = temp;
            }
    cout << "\n After organize: ";
    PrintList(l);
}
void ThemNode(List& l) // add node
{
    int x;
    cout << "\nPlease type the value for adding: ";cin >> x;
    if (x < l.Head->infor)
    {
        Node* p = CreateNode(x);
        AddHead(l, p);
    }
    if (x > l.Tail->infor)
    {
        Node* p = CreateNode(x);
        AddTail(l, p);
    }
    for (Node* p = l.Head; p != NULL; p = p->next)
        if (x > p->infor && x < p->next->infor)
        {
            Node* q = CreateNode(x);
            AddAfterQ(l, q, p);
        }
    PrintList(l);
}
bool SoTang(int a)
{
    if (a < 10)
        return false;
    else
    {
        int ChuSo;
        while (a > 9)
        {
            ChuSo = a % 10;
            a = a / 10;
            if (a % 10 > ChuSo)
                return false;
        }
        return true;

    }
}
bool SoChan(int a)
{
    if (a % 2 == 0)
        return true;
    return false;
}
bool KiemTra1(List l)
{
    for (Node* p = l.Head; p != NULL; p = p->next)
        if (SoChan(p->infor) == false)
            return false;
    return true;
}
void KiemTra2(List l)
{
    for (Node* p = l.Head; p != NULL; p = p->next)
        if (SoTang(p->infor))
            cout << "\nMIN to MAX:" << p->infor;
}
void MinMax(List l)
{
    int Max = l.Head->infor, Min = l.Head->infor;
    for (Node* p = l.Head; p != NULL; p = p->next)
    {
        Max = Max < p->infor ? p->infor : Max;
        Min = Min > p->infor ? p->infor : Min;
    }
    cout << "\nMax: " << Max;
    cout << "\nMin: " << Min;
}

int main()
{
    List l;
    CreateList(l);
    InputList(l);
    PrintList(l);
    SapXepTangDan(l);
    ThemNode(l);
    MinMax(l);
    //Searching_number(l);
    
    return 0;
}
