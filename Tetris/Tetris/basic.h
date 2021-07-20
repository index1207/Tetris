#pragma once
namespace basic {
	using byte = char;
	using ubyte = unsigned char;
	using ushort = unsigned short;
	using uint = unsigned int;
	using ulong = unsigned long;
}
namespace ttrs {
	
	struct Point2D {
		short x;
		short y;
		static void gotoxy(short x, short y);
	};
	struct consoleInfo{
		short x;
		short y;
		std::string title;
		Point2D pos;
	};

	class console {
	public:
		console(void) = default;

		console(Point2D size);

		console(Point2D size, const char* title);

		console(consoleInfo& con);
	public:
		void setTitle(const char* title);

		void setSize(short x, short y);

		void setSize(Point2D p);
	private:
		std::string title;
		Point2D size = { 0,0 };
		Point2D pos = { 0,0 };
	};

}

