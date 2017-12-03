#define KERES_UHV( _ebben , _ezt , _igy ) _ebben._igy##Keres( _ezt )

template < typename T > struct UHV
{
	T * holvan ;
	T maxmeret ;
	UHV( T tmaxmeret )
	{
		maxmeret = tmaxmeret ;
		holvan = new T[ maxmeret + 9 ] ;
	}
	
	~ UHV()
	{
		delete[] holvan ;
	}

	inline void Nullaz( T also , T felso )
	{
		for( int i = also ; i <= felso ; i ++ )
		{
			holvan[ i ] = 0 ;
		}
	}


	inline T PH( T ez ) // utfelezeses (PathHalving)
	{
		T h , hh ;
     
		if( ( h = holvan[ ez ] ) ) 
		{
			while( ( hh = holvan[ h ] ) )
			{
				holvan[ ez ] = hh ;
				ez = h ;
				h = hh ;
			}
			ez = h ;
		}
		return ez ;
	}


	inline T PC( T ez ) // tomoriteses (PathCompressing)
	{
		T tez , mo ;
		mo = tez = ez ;
		while ( ( tez = holvan[ tez ] ) )
		{
    	mo = tez ;
		}
		while ( ( tez = holvan[ ez ] ) )
		{
			holvan[ ez ] = mo ;
			ez = tez ;
		}
		return mo ;
	}


	inline void Unio( T egyik , T masik )
	{
		holvan[ egyik ] = masik ;
	}
} ;
