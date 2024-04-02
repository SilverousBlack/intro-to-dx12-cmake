#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>

//#include "info.hxx"

// Overload the  "<<" operators so that we can use cout to 
// output XMVECTOR objects.
std::ostream& XM_CALLCONV operator<<(std::ostream& os, DirectX::FXMVECTOR v)
{
    DirectX::XMFLOAT3 dest;
    DirectX::XMStoreFloat3(&dest, v);

    os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
    return os;
}

int main(){
    std::cout.setf(std::ios_base::boolalpha);
    float stuff = 0.0f;

    // Check support for SSE2 (Pentium4, AMD K8, and above).
    if (!DirectX::XMVerifyCPUSupport()){
        std::cout << "directx math not supported" << std::endl;
        return 0;
    }
    
    DirectX::XMVECTOR p = DirectX::XMVectorZero();
    DirectX::XMVECTOR q = DirectX::XMVectorSplatOne();
    DirectX::XMVECTOR u = DirectX::XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
    DirectX::XMVECTOR v = DirectX::XMVectorReplicate(-2.0f);
    DirectX::XMVECTOR w = DirectX::XMVectorSplatZ(u);

    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "u = " << u << std::endl;
    std::cout << "v = " << v << std::endl;
    std::cout << "w = " << w << std::endl;
    
    return 0;
}