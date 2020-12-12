#pragma once

namespace Frogger
{
	namespace Category
	{
		enum Type
		{
			None = 0,			 // bit fied operator
			SceneGroundLayer	= 1 << 0,
			Frog				= 1 << 1,
			Car1				= 1 << 2,
			RaceCar1			= 1 << 3,
			RaceCar2			= 1 << 4,
			Truck				= 1 << 5,
			Tractor				= 1 << 6,
			Track				= 1 << 7,
			Water				= 1 << 8,

			Car = Car1 | RaceCar1 | RaceCar2 | Truck | Tractor,

		};
	}
}
