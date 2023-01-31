
#include "ISort.h"
#include "Names.h"

int ISort::GetComprasionCounter()
{
	return comparisonCounter;
}

int ISort::GetSwapCountrt()
{
	return swapCounter;
}

void ISort::PrintCounters()
{
	
	std::cout << "|" << comparisonCounter << "        |" << swapCounter << "    |" << std::endl;
}

void ISort::Print() 
{

}

