#pragma once
#ifdef vector2d
typedef	Skele_lib::Math::V2d<int>       V2dI;
typedef Skele_lib::Math::V2d<float>     V2dF;
typedef Skele_lib::Math::V2d<double>    V2dD;
#endif ///def vector2d
#ifdef arr 
typedef Skele_lib::Utils::Array<int>    ArrayI;
typedef Skele_lib::Utils::Array<float>  ArrayF;
typedef Skele_lib::Utils::Array<double> ArrayD;
#endif