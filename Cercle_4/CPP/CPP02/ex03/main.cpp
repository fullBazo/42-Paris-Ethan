#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point a( 0.0f, 0.0f );
	Point b( 10.0f, 0.0f );
	Point c( 5.0f, 10.0f );

	std::cout << "=== Point clairement a l'interieur ===" << std::endl;
	Point inside( 5.0f, 3.0f );
	std::cout << "bsp(inside) = " << bsp( a, b, c, inside ) << " (attendu: 1)" << std::endl;

	std::cout << "\n=== Point clairement a l'exterieur ===" << std::endl;
	Point outside( 20.0f, 20.0f );
	std::cout << "bsp(outside) = " << bsp( a, b, c, outside ) << " (attendu: 0)" << std::endl;

	std::cout << "\n=== Point sur un sommet ===" << std::endl;
	std::cout << "bsp(a) = " << bsp( a, b, c, a ) << " (attendu: 0)" << std::endl;
	std::cout << "bsp(b) = " << bsp( a, b, c, b ) << " (attendu: 0)" << std::endl;
	std::cout << "bsp(c) = " << bsp( a, b, c, c ) << " (attendu: 0)" << std::endl;

	std::cout << "\n=== Point sur un bord (milieu de a-b) ===" << std::endl;
	Point onEdge( 5.0f, 0.0f );
	std::cout << "bsp(onEdge) = " << bsp( a, b, c, onEdge ) << " (attendu: 0)" << std::endl;

	std::cout << "\n=== Point juste au-dessus du bord a-b (interieur) ===" << std::endl;
	Point justInside( 5.0f, 0.1f );
	std::cout << "bsp(justInside) = " << bsp( a, b, c, justInside ) << " (attendu: 1)" << std::endl;

	std::cout << "\n=== Point juste en dessous du bord a-b (exterieur) ===" << std::endl;
	Point justOutside( 5.0f, -0.1f );
	std::cout << "bsp(justOutside) = " << bsp( a, b, c, justOutside ) << " (attendu: 0)" << std::endl;

	std::cout << "\n=== Triangle degenere (points alignes) ===" << std::endl;
	Point d( 0.0f, 0.0f );
	Point e( 5.0f, 0.0f );
	Point f( 10.0f, 0.0f );
	Point anywhere( 5.0f, 1.0f );
	std::cout << "bsp(degenere) = " << bsp( d, e, f, anywhere ) << " (attendu: 0)" << std::endl;

	return 0;
}