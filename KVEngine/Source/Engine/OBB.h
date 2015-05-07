#ifndef ORIENTATION_ALIGNED_BOUNDING_BOX
#define ORIENTATION_ALIGNED_BOUNDING_BOX

#include "BoundingVolume.h"

namespace KVE
{
	namespace Collisions
	{
		class OBB : BoundingVolume
		{
		public:
			OBB( );
			OBB( DirectX::XMFLOAT3 position, DirectX::XMFLOAT3 frontTopRight, DirectX::XMFLOAT3 backBottomLeft );
			~OBB( );

			DirectX::XMFLOAT3 getCollisionFrontTopRight( void ){ return collisionFrontTopRight; };
			DirectX::XMFLOAT3 getCollisionFrontTopLeft( void ){ return collisionFrontTopLeft; };
			DirectX::XMFLOAT3 getCollisionFrontBottomRight( void ){ return collisionFrontBottomRight; };
			DirectX::XMFLOAT3 getCollisionFrontBottomLeft( void ){ return collisionFrontBottomLeft; };
			DirectX::XMFLOAT3 getCollisionBackTopRight( void ){ return collisionBackTopRight; };
			DirectX::XMFLOAT3 getCollisionBackTopLeft( void ){ return collisionBackTopLeft; };
			DirectX::XMFLOAT3 getCollisionBackBottomRight( void ){ return collisionBackBottomRight; };
			DirectX::XMFLOAT3 getCollisionBackBottomLeft( void ){ return collisionBackBottomLeft; };
			
			DirectX::XMFLOAT3 getPosition( void ){ return position; };
			DirectX::XMFLOAT3 getRotation( void ){ return rotation; };
			DirectX::XMFLOAT3 getScale( void ){ return scale; };

			//set pos, rot, scale and update collision points of OABB
			void setPosition( DirectX::XMFLOAT3 vPosition );
			void setRotation( DirectX::XMFLOAT3 vRotation );
			void setScale( DirectX::XMFLOAT3 vScale );

			f32 getWidth( void ){ return width; };
			f32 getHeight( void ){ return height; };
			f32 getDepth( void ){ return depth; };

			IntersectionValue intersects( BoundingVolume other );

		private:
			UINT indices;									//used for the drawing of the OABB

			DirectX::XMFLOAT3 frontTopRight;				//front top right corner of OABB
			DirectX::XMFLOAT3 frontTopLeft;					//front top left corner of OABB
			DirectX::XMFLOAT3 frontBottomRight;				//front bottom right corner of OABB
			DirectX::XMFLOAT3 frontBottomLeft;				//front bottom left corner of OABB
			DirectX::XMFLOAT3 backTopRight;					//back top right corner of OABB
			DirectX::XMFLOAT3 backTopLeft;					//back top left corner of OABB
			DirectX::XMFLOAT3 backBottomRight;				//back bottom right corner of OABB
			DirectX::XMFLOAT3 backBottomLeft;				//back bottom left corner of OABB

			DirectX::XMFLOAT3 collisionFrontTopRight;		//translated top top right corner of OABB used for collisions
			DirectX::XMFLOAT3 collisionFrontTopLeft;		//translated top top left corner of OABB used for collisions
			DirectX::XMFLOAT3 collisionFrontBottomRight;	//translated top bottom right corner of OABB used for collisions
			DirectX::XMFLOAT3 collisionFrontBottomLeft;		//translated top bottom left corner of OABB used for collisions
			DirectX::XMFLOAT3 collisionBackTopRight;		//translated back top right corner of OABB used for collisions
			DirectX::XMFLOAT3 collisionBackTopLeft;			//translated back top left corner of OABB used for collisions
			DirectX::XMFLOAT3 collisionBackBottomRight;		//translated back bottom right corner of OABB used for collisions
			DirectX::XMFLOAT3 collisionBackBottomLeft;		//translated back bottom left corner of OABB used for collisions

			DirectX::XMFLOAT3 position;
			DirectX::XMFLOAT3 rotation;
			DirectX::XMFLOAT3 scale;

			f32 width;
			f32 height;
			f32 depth;

			//used to keep in sync with the characteristics of the enclosed object
			void UpdateCollisionPoints( );
		};
	}
}

#endif
