/*
    Chapter 1 Execises Playground
    (c) 2024 SilverousBlack
*/

#include <windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

#include <iostream>
#include <set>

#include "info.hxx"

std::ostream &XM_CALLCONV operator<<(std::ostream &os, DirectX::FXMVECTOR v)
{
    DirectX::XMFLOAT3 dest;
    DirectX::XMStoreFloat3(&dest, v);

    os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
    return os;
}

int main(int argc, char *argv[])
{
    // formalize arguments
#if defined(DEBUG) | defined(_DEBUG)
    std::cout << "Formalizing command args." << std::endl << "Argument count: " << argc - 1 << std::endl;
#endif

    std::set<std::string> args;
    for (int ii = 1; ii < argc; ii++){
        std::string buf = argv[ii];
#if defined(DEBUG) | defined(_DEBUG)
        std::cout << "arg [" << ii << "]: " << buf << std::endl;
#endif
        std::string symbol = "";
        if (buf == "-h" | buf == "--help") {
            std::cout << argv[0] << " [FLAGS]" << std::endl;
            std::cout << std::endl << "Flags:"
                << "\t -h | --help \t show this help message." << std::endl
                << "\t -V | --version \t show version" << std::endl
                << "\t -a | --all \t show all." << std::endl
                << "\t -[n] | --ex[n] \t show exercise [n]." << std::endl;
            break;
        }
        else if (buf == "-V" | buf == "--version") {
            std::cout << argv[0] << std::endl
                << PROJECT_NAME << " v" << PROJECT_VERSION << std::endl;
            break;
        }
        else if (buf == "-a" | buf == "--all") {
            args.insert("all");
            break;
        }
        else if (buf == "-1" | buf == "--ex1") symbol = "ex1";
        else if (buf == "-2" | buf == "--ex2") symbol = "ex2";
        else if (buf == "-4" | buf == "--ex4") symbol = "ex4";
        else if (buf == "-5" | buf == "--ex5") symbol = "ex5";
        else if (buf == "-6" | buf == "--ex6") symbol = "ex6";
        else {
            std::cout << "bad argument detected!" << std::endl;
            std::cout << argv[0] << " [FLAGS]" << std::endl;
        }
        args.insert(symbol);
    }

#if defined(DEBUG) | defined(_DEBUG)
    std::cout << "Arguments captured: " << std::endl
              << "\t";
    for (auto &arg : args)
        std::cout << arg;
    std::cout << std::endl;
#endif

    args.insert("all");

    if (args.size() == 0){
#if defined(DEBUG) | defined(_DEBUG)
        std::cout << "No arguments provided." << std::endl;
        std::cout << argv[0] << " [FLAGS]" << std::endl;
        std::cout << std::endl << "Flags:" << std::endl
            << "\t -h | --help \t show this help message." << std::endl
            << "\t -V | --version \t show version" << std::endl
            << "\t -a | --all \t show all." << std::endl
            << "\t -[n] | --ex[n] \t show exercise [n]." << std::endl;
#endif
        return 0;
    }

    std::cout.setf(std::ios_base::boolalpha);

    if (!DirectX::XMVerifyCPUSupport()){
        std::cout << "DirectX Math not supported" << std::endl;
        return 0;
    }

    if (args.find("all") != args.end() || args.find("ex1") != args.end()){
        DirectX::XMVECTOR u = DirectX::XMVectorSet(1.0f, 2.0f, 0.0f, 0.0f);
        DirectX::XMVECTOR v = DirectX::XMVectorSet(3.0f, -4.0f, 0.0f, 0.0f);
        std::cout << "1: u = " << u << ", v = " << v << std::endl;
        std::cout << "\ta.) u + v = " << DirectX::operator+(u, v) << std::endl;
        std::cout << "\tb.) u - v = " << DirectX::operator-(u, v) << std::endl;
        std::cout << "\tc.) 2u + (v/2) = " << DirectX::operator+(DirectX::operator*(2, u), DirectX::operator/(v, 2)) << std::endl;
        std::cout << "\td.) -2u + v = " << DirectX::operator+(DirectX::operator*(-2, u), v) << std::endl;
    }
    if (args.find("all") != args.end() || args.find("ex2") != args.end()){
        DirectX::XMVECTOR u = DirectX::XMVectorSet(-1.0f, 3.0f, 2.0f, 0.0f);
        DirectX::XMVECTOR v = DirectX::XMVectorSet(3.0f, -4.0f, 1.0f, 0.0f);
        std::cout << "2: u = " << u << ", v = " << v << std::endl;
        std::cout << "\ta.) u + v = " << DirectX::operator+(u, v) << std::endl;
        std::cout << "\tb.) u - v = " << DirectX::operator-(u, v) << std::endl;
        std::cout << "\tc.) 3u + 2v = " << DirectX::operator+(DirectX::operator*(3, u), DirectX::operator*(2, v)) << std::endl;
        std::cout << "\td.) -2u + v = " << DirectX::operator+(DirectX::operator*(-2, u), v) << std::endl;
    }
    // TODO: ex3
    if (args.find("all") != args.end() || args.find("ex4") != args.end()){
        DirectX::XMVECTOR a = DirectX::XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
        DirectX::XMVECTOR b = DirectX::XMVectorSet(-2.0f, 0.0f, 4.0f, 0.0f);
        std::cout << "4: 2([1, 2, 3] - x) - [-2, 0, 4] = -2[1, 2, 3]. Solve for x." << std::endl
            << "\tLET:" << std::endl
            << "\t\ta = " << a << std::endl
            << "\t\tb = " << b << std::endl
            << "\tSOLUTION:" << std::endl
            << "\t\t= 2(a-x) - b = -2a" << std::endl
            << "\t\t= 2a - 2x = b - 2a" << std::endl
            << "\t\t= 2a - (b - 2a) = 2x" << std::endl
            << "\t\t= 4a - b = 2x" << std::endl
            << "\t\t= (4a - b)/2 = x" << std::endl;
        DirectX::XMVECTOR x = DirectX::operator/(DirectX::operator-(DirectX::operator*(4, a), b), 2);
        std::cout << "\tx = " << x << std::endl;
    }
    if (args.find("all") != args.end() || args.find("ex5") != args.end()) {
        // d(V) = V / ||V||
        DirectX::XMVECTOR u = DirectX::XMVectorSet(-1.0f, 3.0f, 2.0f, 0.0f);
        DirectX::XMVECTOR v = DirectX::XMVectorSet(3.0f, -4.0f, 1.0f, 0.0f);
        std::cout << "5: Let u = " << u << " and v = " << v << ". Normalize u and v." << std::endl;
        std::cout << "\td(u) = " << DirectX::XMVector3Normalize(u) << std::endl;
        std::cout << "\td(v) = " << DirectX::XMVector3Normalize(v) << std::endl;
    }
    if (args.find("all") != args.end() || args.find("ex6") != args.end()){
        std::cout << "6: Let k be a scalar and let u = (u_x, u_y, u_z). Prove that ||ku|| = |k|||u||." << std::endl;
        float k, ux, uy, uz = 0.0f;
        std::cout << "\tInput scalar k: "; std::cin >> k;
        std::cout << "\tInput u (space separated): "; std::cin >> ux >> uy >> uz;
        DirectX::XMVECTOR u = DirectX::XMVectorSet(ux, uy, uz, 0.0f);
        bool equality = DirectX::XMVector3Equal(DirectX::XMVector3Length(DirectX::operator*(k, u)), DirectX::operator*(abs(k), DirectX::XMVector3Length(u)));
        std::cout << std::endl 
            << "\tk = " << k << std::endl
            << "\tu = " << u << std::endl
            << "\t||ku|| = " << DirectX::XMVector3Length(DirectX::operator*(k, u)) << std::endl
            << "\t|k|||u|| = " << DirectX::operator*(abs(k), DirectX::XMVector3Length(u)) << std::endl
            << "\t||ku|| == |k|||u|| = " << equality << std::endl;
        /*
            Mathematical Proof:

                GIVEN:
                    ||V|| = \sqrt(V.x^2 + V.y^2 + V.z^2) // for 3D vector
                    ||V|| = \sqrt(\sum^{n}_{i}(V[i]^2)) // general formula

                    kV = [kV.x, kV.y, kV.z] // for 3D vector
                    kV = [kV[0],  ..., kV[n-1]] // general formula

                    \sqrt(k * k) = |k| // via principal root
                
                PROVING ||ku|| == |k| * ||u|| for any-size vector u:

                    ku = [ku[0], ..., ku[n-1]]
                    ||ku|| = \sqrt(\sum^{n}_{i}{(ku[i]^2)})
                           = \sqrt((ku[0])^2 + ... + (ku[n])^2)
                           = \sqrt(k^2 * (u[0]^2 + ... + u[n]^2))
                           = \sqrt(k^2) * \sqrt(u[0]^2 + ... + u[n]^2)
                           = |k| * \sqrt(\sum^{n}_{i}(u[i])^2)
                           = |k| * ||u||,,

                HENCE PROVED ||ku|| == |k| * ||u||
        */
    }
}
