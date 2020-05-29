#include <iostream>
#include <liblas/liblas.hpp>
#include <liblas/factory.hpp>
#include <liblas/reader.hpp>
using namespace std;

int main() {
    ifstream las;
    //文件名写为../lidar.las由于当前文件被编译之后是存在cmake-build-debug内部的，而数据文件我们放在了外面
    las.open("../lidar.las",ios::in|ios::binary);
    if(las){
        liblas::ReaderFactory f;
        liblas::Reader reader=f.CreateWithStream(las);
        liblas::Header const header=reader.GetHeader();
        int VLRsFront=header.GetHeaderSize();
        int VLRsEnd=header.GetDataOffset();
        int PointNum=header.GetPointRecordsCount();
        cout<<"PHB所占字节大小为："<<VLRsFront<<endl;
        cout<<"Point Data起始位置："<<VLRsEnd<<endl;
        cout<<"VLRS 所占的字节大小为："<<VLRsEnd-VLRsFront<<endl;
        cout<<"数据点的总个数："<<PointNum<<endl;
    }
    else{
        cout<<"没有该文件"<<endl;
    }
    return 0;
}
