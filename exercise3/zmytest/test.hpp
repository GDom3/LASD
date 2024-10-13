
#ifndef MYTEST_HPP
#define MYTEST_HPP

/* ************************************************************************** */

void mytest();


void testVettoreMio(unsigned int & , unsigned int & );
void testVettoreIntMio(unsigned int &, unsigned int &);
void testVettoreStringMio(unsigned int &, unsigned int &);

void testListaMio(unsigned int & , unsigned int &);
void testListaIntMio(unsigned int & , unsigned int &);
void testListaStringMio(unsigned int & , unsigned int &);

void testStackaMio(unsigned int &, unsigned int &);
void testStackVecIntMio(unsigned int &, unsigned int &);
void testStackVecStringMio(unsigned int &, unsigned int &);
void testStackLstIntMio(unsigned int &, unsigned int &);
void testStackLstStringMio(unsigned int &, unsigned int &);

void testQueueMio(unsigned int &, unsigned int &);
void testQueueVecIntMio(unsigned int &, unsigned int &);
void testQueueVecStringMio(unsigned int &, unsigned int &);
void testQueueLstIntMio(unsigned int &, unsigned int &);
void testQueueLstStringMio(unsigned int &, unsigned int &);

void testAlberoMio(unsigned int &, unsigned int &);
void testAlberoIntMio(unsigned int &, unsigned int &);
void testAlberoDoubleMio(unsigned int &, unsigned int &);
template <typename Albero>
void testAlberoGenericoIntMio(unsigned int &, unsigned int &);
void testAmbedueAlberoIntMio(unsigned int &, unsigned int &);
template <typename Albero>
void testAlberoGenericoDoubleMio(unsigned int &, unsigned int &);
void testAmbedueAlberoDoubleMio(unsigned int &, unsigned int &);

void testAlberoBSTMio(unsigned int &, unsigned int &);
void testAlberoBSTIntMio(unsigned int &, unsigned int &);

void testIteratoreMio(unsigned int &, unsigned int &);
void testPreIteratoreMio(unsigned int &, unsigned int &);
void testPostIteratoreMio(unsigned int &, unsigned int &);
void testInIteratoreMio(unsigned int &, unsigned int &);
void testBreadthIteratoreMio(unsigned int &, unsigned int &);

void testHashTableMio(unsigned int &, unsigned int &);
template <typename Hash>
void testHashTableIntMio(unsigned int &, unsigned int &);
template <typename Hash>
void testHashTableDoubleMio(unsigned int &, unsigned int &);
template <typename Hash>
void testHashTableStringMio(unsigned int &, unsigned int &);




/* ************************************************************************** */

#endif
