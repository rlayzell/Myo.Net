#pragma once

using namespace System;
using namespace System::Globalization;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

#include "HashCodeHelper.hpp"

namespace MyoNet
{
	namespace Myo
	{
		/// <summary>
		/// A vector of three components.
		/// </summary>
		[DebuggerDisplayAttribute("{ToString(),nq}")]
		[StructLayoutAttribute(LayoutKind::Explicit)]
		public value struct Vector3 sealed : IEquatable<Vector3>, IFormattable
		{
		private:
			[FieldOffsetAttribute(0) ] double _x; 
			[FieldOffsetAttribute(8) ] double _y;
			[FieldOffsetAttribute(16)] double _z;

		public:
			/// <summary>
			/// Represents a vector that has X, Y, and Z values set to zero.
			/// </summary>
			static property Vector3 Zero { Vector3 get( ) { return Vector3(0, 0, 0); } }
			
			/// <summary>
			/// Represents a vector that has X value set to 1 and the Y, Z values set to zero.
			/// </summary>
			static property Vector3 UnitX { Vector3 get( ) { return Vector3(1, 0, 0); } }
			
			/// <summary>
			/// Represents a vector that has Y value set to one and the X, Z values set to zero.
			/// </summary>
			static property Vector3 UnitY { Vector3 get( ) { return Vector3(0, 1, 0); } }
			
			/// <summary>
			/// Represents a vector that has Z value set to one and the X, Y values set to zero.
			/// </summary>
			static property Vector3 UnitZ { Vector3 get( ) { return Vector3(0, 0, 1); } }

			/// <summary>
			/// Initializes a new instance of the <see cref="Vector3"/> with the specified components.
			/// </summary>
			/// <params>
			/// <param name="x">The x component of the <see cref="Vector3"/>.</param>
			/// <param name="y">The y component of the <see cref="Vector3"/>.</param>
			/// <param name="z">The z component of the <see cref="Vector3"/>.</param>
			/// </params>
			Vector3(double x, double y, double z);

			/// <summary>
			/// Gets or sets the x component of the <see cref="Vector3"/>.
			/// </summary>
			property double X 
			{ 
				double get( ) { return _x; } 
				void set(double value) { _x = value; } 
			}
			
			/// <summary>
			/// Gets or sets the y component of the <see cref="Vector3"/>.
			/// </summary>
			property double Y 
			{
				double get( ) { return _y; } 
				void set(double value) { _y = value; }
			}
			
			/// <summary>
			/// Gets or sets the z component of the <see cref="Vector3"/>.
			/// </summary>
			property double Z 
			{ 
				double get( ) { return _z; } 
				void set(double value) { _z = value; } 
			}
			
			/// <summary>
			/// Get or set a component in the <see cref="Vector3"/> by index.
			/// </summary>
			property double default[int] 
			{
				double get(int index) { return *(&_x + index); }
				void set(int index, double value) { *(&_x + index) = value; }
			}

			/// <summary>
			/// Gets the length of the vector.
			/// </summary>
			/// <returns>The length of the <see cref="Vector3"/>.</returns>
			double Length( ) { return System::Math::Sqrt(this->LengthSquared( )); }

			/// <summary>
			/// Gets the length squared of the vector.
			/// </summary>
			/// <returns>The squared length of the <see cref="Vector3"/>.</returns>
			double LengthSquared( ) { return DotProduct(*this, *this); }

			static bool operator == (Vector3 lhs, Vector3 rhs);

			static bool operator != (Vector3 lhs, Vector3 rhs);

			/// <summary>
			/// Adds the specified <see cref="Vector3"/>'s.
			/// </summary>
			static Vector3 operator + (Vector3 lhs, Vector3 rhs);

			/// <summary>
			/// Subtracts a <see cref="Vector3"/> from another.
			/// </summary>
			static Vector3 operator - (Vector3 lhs, Vector3 rhs);

			/// <summary>
			/// Multiplies the <see cref="Vector3"/> by specified scalar <paramref name="value"/>
			/// </summary>
			static Vector3 operator * (Vector3 lhs, double value);
			
			/// <summary>
			/// Multiplies the <see cref="Vector3"/> by specified scalar <paramref name="value"/>
			/// </summary>
			static Vector3 operator * (double value, Vector3 rhs);

			/// <summary>
			/// Divides the <see cref="Vector3"/> by specified scalar <paramref name="value"/>
			/// </summary>
			static Vector3 operator / (Vector3 lhs, double value);

			/// <summary>
			/// Return a new unit <see cref="Vector3"/> corresponding to the same direction as this one.
			/// </summary>
			/// <returns>A unit length vector.</returns>
			Vector3 Normalized( );

			/// <summary>
			/// Calculates the dot product of the <see cref="Vector3"/>'s <paramref name="lhs"/> and <paramref name="rhs"/>.
			/// </summary>
			/// <params>
			/// <param name="lhs">A vector used to calculate the dot product.</param>
			/// <param name="rhs">A vector used to calculate the dot product.</param>
			/// </params>
			/// <returns>The dot product.</returns>
			static double DotProduct(Vector3 lhs, Vector3 rhs);

			/// <summary>
			/// Calculates the cross product of the <see cref="Vector3"/>'s <paramref name="lhs"/> and <paramref name="rhs"/>.
			/// </summary>
			/// <params>
			/// <param name="lhs">A vector used to calculate the cross product.</param>
			/// <param name="rhs">A vector used to calculate the cross product.</param>
			/// </params>
			/// <returns>A new vector representing the cross product.</returns>
			static Vector3 CrossProduct(Vector3 lhs, Vector3 rhs);

			/// <summary>
			/// Calculates the angle between the <see cref="Vector3"/>'s <paramref name="lhs"/> and <paramref name="rhs"/>.
			/// </summary>
			/// <params>
			/// <param name="lhs">A vector used to calculate the angle from.</param>
			/// <param name="rhs">A vector used to calculate the angle to.</param>
			/// </params>
			/// <returns>The angle in radians.</returns>
			static double AngleTo(Vector3 lhs, Vector3 rhs);

			/// <summary> 
			/// Returns the hash code for this Vector3 instance. 
			/// </summary> 
			/// <returns>The hash code.</returns> 
			int GetHashCode( ) override;

			/// <summary>
			/// Determines whether the specified object is equal to this Vector3 instance.
			/// </summary>
			/// <params>
			/// <param name="obj">The Object to compare against.</param>
			/// </params>
			/// <returns>True if the Object is equal to this Vector3; False otherwise.</returns>
			bool Equals(Object^ obj) override;

			/// <summary>
			/// Determines whether the specified Vector3 is equal to this Vector3 instance.
			/// </summary>
			/// <params>
			/// <param name="other">The Vector3 to compare against.</param>
			/// </params>
			/// <returns>True if the Vector3 is equal to this Vector3; False otherwise.</returns>
			virtual bool Equals(Vector3 other);

			/// <summary>
			/// Returns a String representing this Vector3 instance.
			/// </summary>
			/// <returns>The string representation</returns>
			virtual String^ ToString( ) override;

			/// <summary>
			/// Returns a String representing this Vector3 instance, using the specified format.
			/// </summary>
			/// <params>
			/// <param name="format">The format of the individual elements.</param>
			/// </params>
			/// <returns>The string representation</returns>
			String^ ToString(String^ format);

			/// <summary>
			/// Returns a String representing this Vector3 instance, using the specified format and a IFormatProvider.
			/// </summary>
			/// <params>
			/// <param name="format">The format of the individual elements.</param>
			/// <param name="formatProvider">The format provider used to format individual elements.</param>
			/// </params>
			/// <returns>The string representation</returns>
			virtual String^ ToString(String^ format, IFormatProvider^ formatProvider);
		};
	}
}
