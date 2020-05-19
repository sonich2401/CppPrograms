
#define OLC_PGE_APPLICATION
#define OLC_PGEX_GRAPHICS2D
#define OLC_PGEX_ANIMSPR

#include "olcPixelGameEngine.h"
#include "test.h"
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		// Name you application
		sAppName = "Frogger";
	}

public:
	rendev::aniSprite sprite;
	rendev::aniSprite water;
	bool OnUserCreate() override
	{
		sprite.setpoint(this);
		//olc::Pixel::ALPHA;
		sprite.AddState("forwards", 0.1f, {
		"C://Users/mener/OneDrive/Desktop/Image1.png",
		"C://Users/mener/OneDrive/Desktop/Image2.png",
		"C://Users/mener/OneDrive/Desktop/Image1.png",
		"C://Users/mener/OneDrive/Desktop/Image2.png" });
		sprite.SetState("forwards");
			water.setpoint(this);
			water.AddState("still", 1.0f, {
"C://Users/mener/OneDrive/Desktop/water1.png",
"C://Users/mener/OneDrive/Desktop/water2.png",
"C://Users/mener/OneDrive/Desktop/water1.png",
"C://Users/mener/OneDrive/Desktop/water2.png" });
			water.SetState("still");
		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
olc::vf2d pos= {float(GetMouseX()),float(GetMouseY())};
		sprite.GetMultiFrame(fElapsedTime,pos);
		water.GetMultiFrame(fElapsedTime, {float(10),float(10)});
		return true;
	}
};

int main()
{
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}
