///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic Node class.  May be used as a base class for a number of data
/// structures.  Not all of the fields need to be used.
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "config.h"
#include "Node.h"

using namespace std;


/// #### Sample Output
/// @code
///     ==============================================
///     Node    this                0x7ffeeaa7e580
///     Node    next                0
/// @endcode
///
void Node::dump() const {
   FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << endl ;
   FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << endl ;
}


/// A generic comparison based on the memory address of the object.
///
/// @return true if `node1 > node2`
bool Node::compareByAddress ( const Node* node1, const Node* node2 ) {
   if( node1 > node2 )
      return true;
   return false;
}


/// @param rightSide The `this` member is the left side of the `>` operator.
///                  `rightSide` is the right side of the `>` operator.
/// @return `true` if `leftSide > rightSide`
bool Node::operator>(const Node &rightSide) {
   // `this` is the leftSide of the operator, so compare:
   // leftSide > rightSide

   return compareByAddress( this, &(Node&)rightSide );
}


/// This method checks the Node.  If something is not right,
/// print out a message and stop the validation.  It will not throw an
/// exception.
///
/// @return True if the Node is healthy
bool Node::validate() const noexcept {
   if( next == nullptr ) {
      return true;  /// `nullptr` is a valid value for the next pointer.
   }

   /// @internal Perform a rudimentary recursive loop test and ensure
   ///           the next pointer does not refer back to itself.
   ///           This also has the benefit of dereferencing the
   ///           next pointer and ensuring it points to a valid address.
   if( next == next->next ) {
      cout << PROGRAM_NAME << ": Recursive loop detected:  next points to itself!" ;
      return false;
   }

   return true;
}
