///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once


class Node {
   friend class SinglyLinkedList;
   friend class DoublyLinkedList;


protected:
   Node* next = nullptr;
   Node* prev = nullptr;

   bool compareByAddress ( const Node* node1, const Node* node2 ) ;

public:
   void dump() const;
   virtual bool operator>(const Node& rightSide);
}; // class Node
