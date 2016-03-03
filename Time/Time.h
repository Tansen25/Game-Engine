#ifndef Time_h
#define Time_h


	/**
	 * For specifying a duration when
	 * @link Time::Time() creating Time @endlink.
	 */
	enum Duration
	{
		/** For constructing a Time of zero. */
		TIME_ZERO,

		/** For constructing one NTSC 60 hz frame of Time. */
		TIME_NTSC_FRAME,

		/** For constructing one NTSC 60 hz frame of Time. */
		TIME_NTSC_30_FRAME,

		/** For constructing one PAL 50 hz frame of Time. */
		TIME_PAL_FRAME,

		/** For constructing one millisecond of Time. */
		TIME_ONE_MILLISECOND,

		/** For constructing one second of Time. */
		TIME_ONE_SECOND,

		/** For constructing one minute of Time. */
		TIME_ONE_MINUTE,

		/** For constructing one hour of Time. */
		TIME_ONE_HOUR,

		/** 
		 * For constructing the most <i>negative</i> Time 
		 * that can be represented. 
		 */
		TIME_MIN,

		/** 
		 * For constructing the most positive Time 
		 * that can be represented. 
		 */
		TIME_MAX,

		Duration_integerEnforcer = 0x7FFFFFFF
	};



//---------------------------------------------------------------------------
// CLASS DECLARATION:
//---------------------------------------------------------------------------

	class Time
	{

		public:
			///-----------------------------------------------------------------
			/// @name Friends
			///-----------------------------------------------------------------

			/**
			 * @return The product of the specified float and Time. 
			 *
			 * @b Example:
			 *    @code 
			 *    const Time halfSecond = 0.5f * Time(ONE_SECOND);
			 *    @endcode
			 */
			friend const Time operator*( const float, const Time & );
	
	
			/** 
			 * @return The product of the specified integer and Time. 
			 *
			 * @b Example:
			 *    @code 
			 *    const Time fourMinutes = 4 * Time(ONE_MINUTE);
			 *    @endcode
			 */
			friend const Time operator*( const int, const Time & );
	
			//@}
	
	
	
		public:
			///-----------------------------------------------------------------
			/// @name Constructors / Destructors / Assignment
			///-----------------------------------------------------------------
	
			//@{
	
			/** Creates a Time equal to Time(ZERO). */ 
			inline Time();
	
	
			/** 
			 * Creates the specific amount of Time. 
			 *
			 * @b Example:
			 *    @code
			 *    const Time oneSecond( ONE_SECOND );
			 *    @endcode
			 */
			explicit Time( const Duration );
	
	
			/** Creates a copy of the specified Time. */ 
			inline Time( const Time& );
	
	
			/** 
			 * Assigns the right-hand side to this Time. 
			 * @return this Time.
			 *
			 * @b Example:
			 *    @code 
			 *    const Time tickDuration = Time(NTSC_DURATION);
			 *    @endcode
			 */ 
			inline Time& operator=( const Time& rhs );
	
	
			~Time()
			{ }
	
			//@}
	
	
	
		public:
			///-----------------------------------------------------------------
			/// @name Comparisons
			///-----------------------------------------------------------------
	
			//@{
	
			/** 
			 * @return true if this Time is equal to the right-hand side. 
			 *
			 * @b Example:
			 *    @code 
			 *    assert( Time(ONE_HOUR)   == 60 * Time(ONE_MINUTE) );
			 *    assert( Time(ONE_MINUTE) == 60 * Time(ONE_SECOND) );
			 *    @endcode
			 */
			bool operator==( const Time& rhs ) const;
	
	
			/** 
			 * @return true if this Time is not equal to the right-hand side. 
			 */
			bool operator!=( const Time& rhs ) const;
	
	
			/** 
			 * @return true if this Time is less than the right-hand side.
			 *
			 * @b Example:
			 *    @code 
			 *    bool couldBeOttosMileTime( const Time t )
			 *    {
			 *       return( t < 4 * Time(ONE_MINUTE) );
			 *    }
			 *    @endcode
			 */
			bool operator<( const Time& rhs ) const;
	
	
			/** 
			 * @return true if this Time is less or equal to the right-hand side.
			 */
			bool operator<=( const Time& rhs ) const;
	
	
			/** 
			 * @return true if this Time is greater than the right-hand side.
			 */
			bool operator>( const Time& rhs ) const;
	
	
			/** 
			 * @return true if this Time is greather than or equal to
			 *  the right-hand side.
			 */
			bool operator>=( const Time& rhs ) const;
	
			//@}
	
	
	
		public:
			///-----------------------------------------------------------------
			/// @name Negation / Addition / Subtraction
			///-----------------------------------------------------------------
	
			//@{
	
			/** 
			 * @return A negative copy of this Time. 
			 *
			 * @b Example:
			 *    @code 
			 *    void neverFail( const Time t )
			 *    {
			 *       assert( t + (-t) == Time(ZERO) );
			 *    }
			 *    @endcode
			 */
			const Time operator-() const;
	
	
			/** 
			 * @return The sum of this Time and the right-hand side. 
			 *
			 * @b Example:
			 *    @code 
			 *    void neverFail( const Time t )
			 *    {
			 *       assert( t + t == 2 * t );
			 *    }
			 *    @endcode
			 */
			const Time operator+( const Time& rhs ) const;
	
	
			/** 
			 * @return The difference between this Time and the right-hand side. 
			 *
			 * @b Example:
			 *    @code 
			 *    void neverFail( const Time t )
			 *    {
			 *       assert( t - t == Time(ZERO) );
			 *    }
			 *    @endcode
			 */
			const Time operator-( const Time& rhs ) const;
	
	
			/** 
			 * Adds the right-hand side to this Time.
			 *
			 * @return This Time. 
			 *
			 * @b Example:
			 *    @code 
			 *    void zeroOutTime( Time& t )
			 *    {
			 *       t += (-t);
			 *       assert( Time(ZERO) == t );
			 *    }
			 *    @endcode
			 */
			Time& operator+=( const Time& rhs );
	
	
			/** 
			 * Subtracts the right-hand side from this Time.
			 *
			 * @return This Time. 
			 *
			 * @b Example:
			 *    @code 
			 *    void zeroOutTime( Time& t )
			 *    {
			 *       t -= t;
			 *       assert( Time(ZERO) == t );
			 *    }
			 *    @endcode
			 */
			Time& operator-=( const Time& rhs );
	
			//@}
	
	
	
		public:
			///-----------------------------------------------------------------
			/// @name Multiplication
			///-----------------------------------------------------------------
	
			//@{
	
			/** 
			 * @return The product of this Time and the specified float. 
			 *
			 * @b Example:
			 *    @code 
			 *    const Time halfSecond = Time(ONE_SECOND) * 0.5f;
			 *    @endcode
			 */
			const Time operator*( const float ) const;
	
	
			/** 
			 * @return The product of this Time and the specified integer. 
			 *
			 * @b Example:
			 *    @code 
			 *    const Time fourMinutes = Time(ONE_MINUTE) * 4;
			 *    @endcode
			 */
			const Time operator*( const int ) const;
	
	
			/** 
			 * Multiplies this Time by the specified float.
			 *
			 * @return This Time. 
			 *
			 * @b Example:
			 *    @code 
			 *    void decayTime( Time& t )
			 *    {
			 *       t *= 0.95f;
			 *    }
			 *    @endcode
			 */
			Time& operator*=( const float );
	
	
			/** 
			 * Multiplies this Time by the specified integer.
			 *
			 * @return This Time. 
			 *
			 * @b Example:
			 *    @code 
			 *    void doubleTime( Time& t )
			 *    {
			 *       t *= 2;
			 *    }
			 *    @endcode
			 */
			Time& operator*=( const int );
	
			//@}
	
	
	
		public:
			///-----------------------------------------------------------------
			/// @name Division
			///-----------------------------------------------------------------
	
			//@{
	
			/**
			 * @return The ratio of this Time divided by the denominator Time.
			 *
			 * @note Dividing by Time::ZERO is undefined.
			 */
			float operator/( const Time& denominator ) const;
	
	
			/** 
			 * @return The result of dividing this Time and by the
			 * specified float.
			 *
			 * @note Dividing by zero is undefined.
			 */
			const Time operator/( const float denominator ) const;
	
	
			/** 
			 * @return The result of dividing this Time and by the
			 * specified integer.
			 *
			 * @note Dividing by zero is undefined.
			 */
			const Time operator/( const int denominator ) const;
	
	
			/** 
			 * Divides this Time by the specified float.
			 *
			 * @return This Time. 
			 *
			 * @note Dividing by zero is undefined.
			 */
			Time& operator/=( const float );
	
	
			/** 
			 * Divides this Time by the specified integer.
			 *
			 * @return This Time. 
			 *
			 * @note Dividing by zero is undefined.
			 */
			Time& operator/=( const int );
	
			//@}
	
	
	
		public:
			///-----------------------------------------------------------------
			/// @name Quotient / Remainder
			///-----------------------------------------------------------------
	
			//@{
	
			/**
			 * @return The <i>truncated</i>, integral division of the
			 * numerator and denominator.  In other words,
			 * the result of the division is rounded down to the nearest
			 * integer.
			 *
			 * @note Dividing by Time(ZERO) is undefined.
			 */
			static int 	quotient( const Time& numerator, const Time& denominator );
	
	
			/**
			 * @return The remainder of dividing the numerator into the
			 * denominator.  This is the equivalent of a modulus operation.
			 *
			 * @note Dividing by Time(ZERO) is undefined.
			 */
			static const Time 	remainder( const Time& numerator, const Time& denominator );
	
			//@}
	
	
	
		private:
			typedef int Representation;
	
	
		private:
			explicit Time( const Representation );
	
	
		private:
			Representation _rawTime;
	};




//---------------------------------------------------------------------------
// INLINED IMPLEMENTATION:
//---------------------------------------------------------------------------
Time::Time(): _rawTime( 0 )
{
}


Time::Time( const Time& rhs ): _rawTime( rhs._rawTime )
{
}


Time& Time::operator=( const Time& rhs )
{
	if ( this != &rhs )
	{
		this->_rawTime = rhs._rawTime;
	}

	return( *this );
}



#endif  

