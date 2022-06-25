#ifndef OBJECT_H
#define OBJECT_H

#include <MyEngine/Utils/pch.h>

namespace MyEngine {

	class Object
	{
	public:
		/// <summary>
		/// Object constructor
		/// </summary>
		/// <param name="name">Object name</param>
		/// <param name="is_active">Object active boolean</param>
		Object(const std::string name, bool is_active = true)
		{
			this->name = name;
			this->is_active = is_active;
		}

		/// <summary>
		/// Activate object
		/// </summary>
		void activate() { is_active = true; }

		/// <summary>
		/// Deactivate object
		/// </summary>
		void deactivate() { is_active = false; };

		/// <summary>
		/// Checks if object is currently active
		/// </summary>
		/// <returns>is active boolean</returns>
		bool hasActivity()const { return is_active; }

		/// <summary>
		/// Get an object name
		/// </summary>
		/// <returns>object name</returns>
		std::string getName()const { return name; }

	protected:
		bool is_active;
		std::string name;
	};
}

#endif // !OBJECT_H