#ifndef IOBJECT_HPP
#define IOBJECT_HPP

namespace object 
{
	class IObject
	{
	public:
		virtual void Draw() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Clean() = 0;
	};
}
#endif // IOBJECT_HPP