#include <iostream>
#define Max 100
#define TRUE  1
#define FALSE  0

using namespace std;


// ham kiem tra khoang cach giua 2 dinh

int khoangcach(int B[Max][Max], int n, int a, int b)// tra ve khoang cach tu dinh a den dinh b tren do thi
{
    int i, sum = 0;
    int S[n], Len[n];
    // tinh gia tri vo cung (sum)
    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum += B[i][j];
    // dat vo cung cho tat ca cap canh khong noi voi nhau
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && B[i][j] == 0)
                B[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++) {
        Len[i] = sum;                   // khoi tao do dai tu a toi moi dinh la vo cung
        S[i] = 0;                       // danh sach cac diem da xet
    }

    Len[a] = 0;                         // dat do dai tu a -> a la 0

    while (S[b] == 0)
    {                                // trong khi diem cuoi chua duoc xet
        for (i = 0; i < n; i++)          // tim 1 vi tri ma khong phai la vo cung
            if (!S[i] && Len[i] < sum)
                break;

        // i >=n tuc la duyet het cac dinh ma khong the tim thay dinh b -> thoat
        if (i >= n)
            {
            cout<<"khong tim thay dinh "<<b<< endl;
            break;
            }

        for (int j = 0; j < n; j++)
        {
            if (!S[j] && Len[i] > Len[j]) i = j;  // tim diem co vi tri ma do dai la min
        }

        S[i] = 1;                         // cho i vao danh sach xet roi

        for (int j = 0; j < n; j++)      // tinh lai do dai cua cac diem chua xet
        {
            if (!S[j] && Len[i] + B[i][j] < Len[j])
            {
                Len[j] = Len[i] + B[i][j];      // thay doi Len
            }
        }
    }
    return Len[b];
}

  /* kiem tra viec tim khoang cach dung khong
    cout<<"da kiem tra"<< endl;
    if (Len[b] > 0 && Len[b] < sum)
    {
        cout<< "koang cach la: "<< Len[b]<< endl;

        // truy vet
        while (i != a)
        {
            cout<<i<< " <--";
            i = P[i];
        }
        cout<< a;
    }
    else
    {
        cout<<"khong co duong di tu "<<a<<"den "<< b<< endl;
    }
}
*/
// tim duong di tu dinh dau den dinh dich
void timduong(int B[Max][Max], int n, int s, int t)// tim duong tu dinh s den dinh t
{
   int truoc[Max], chuaxet[Max], danhdau[Max];//mảng đánh dấu.

 for(int i= 0; i< n; i++)
 {
  chuaxet[i]= TRUE;
  truoc[i]= 0;
 }

 int dauQ, cuoiQ, u;
 dauQ= 1; cuoiQ= 1;        //khoi tao mang danh dau.
 danhdau[dauQ]= s;
 chuaxet[s]= FALSE;       //them dinh dau vao mang danh dau.
 while (dauQ<= cuoiQ)     //mang danh dau chưa rong.
{
  u= danhdau[dauQ];     //lay dinh u trong mang danh dau.
  dauQ= dauQ+1;
  for (int p= 0; p< n; p++)
  {
   if(B[u][p] && chuaxet[p])
   {
    cuoiQ= cuoiQ+1;
    danhdau[cuoiQ]= p;
    chuaxet[p]= FALSE;
    truoc[p]= u;
   }
  }
 }

 if(truoc[t]==0)
 {
  cout<<"Khong co duong di tu "<<s<< " den "<<t;
  return;
 }
 cout<<"Duong di tu "<<s<<" den "<<t<<" la: ";
 int j = t;
 cout<<t<<"<=";
 while(truoc[j]!=s)
 {
  cout<<truoc[j]<<"<=";
  j=truoc[j];
 }
 cout<<s;
}


int main()
{
    // nhập vào đồ thị
    int n, m, a, b, c, d, r;
    int A[Max][3];
    cout<< " nhap vao so dinh va so canh cua do thi :"<< endl;
    cin>> n>> m;
    cout<< "\n nhap vao lan luot cac canh cua do thi cung trong so tuong ung: "<< endl;
    for(int i= 0; i< m; i++)
    {
        cout<< "canh thu "<<i+1<< " la :"<< endl;
        for(int j=0; j< 2; j++)
            cin>> A[i][j];
        cout<< "\ntrong so la: ";
        cin>> A[i][2];
    }
    cout<< "\n nhap vao 2 dinh xuat phat a va b: "<< endl;
    cin>> a>> b;
    cout<< "\n nhap vao 2 dinh dich c va d: "<< endl;
    cin>> c>> d;
    cout<< "\nnhap vao khoang cach r: "<< endl;
    cin>> r;

// chuyen sang ma tran danh sach ke
    int B[Max][Max];
    for(int i= 0; i< m; i++)
       {
           int p, q;
           p= A[i][0]; q= A[i][1];
           B[p][q]= A[i][2];
           B[q][p]= A[i][2];
       }
// tim dinh mix va max de phuc vu in ra khi can thiet
int Amin= A[0][0];
for(int i=0; i< m; i++)
    for(int j=0; j< 2; j++)
    if(A[i][j]< Amin) Amin=A[i][j];

 int Amax= A[0][0];
 for(int i=0; i< m; i++)
    for(int j=0; j< 2; j++)
    if(A[i][j]> Amax) Amax=A[i][j];

/* in thu ra ma tran danh sach ke de kiem tra
    for(int i=Amin; i<Amax; i++)
       {
        for(int j=Amin; j<Amax; j++)
        cout<<B[i][j]<<"  ";
        cout<< endl;
       }
*/
// so sanh 2 quang duong phai di cua 2 robot xem con nao di truoc
int robot1= khoangcach(B, n, a, c);
int robot2= khoangcach(B, n, b, d);
if(robot1>= robot2)
{
    timduong(B, n, b, d);
    timduong(B, n, a, c);
}
if(robot1< robot2)
{
    timduong(B, n, a, c);
    timduong(B, n, b, d);
}
    return 0;
}
