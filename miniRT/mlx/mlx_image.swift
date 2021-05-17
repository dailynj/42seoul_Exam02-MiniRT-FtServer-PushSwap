

import Metal


public class MlxImg
{
    public var texture: MTLTexture
///    var texture_buff: MTLBuffer

    public var texture_sizeline: Int
    public var texture_data: UnsafeMutablePointer<UInt32>
    public var texture_wid: Int
    public var texture_heig: Int

    public var onGPU = 0

     convenience public init(d device:MTLDevice, w wid:Int, h heig:Int)
     {
	self.init(d:device, w:wid, h:heig, t:0)
     }

     public init(d device:MTLDevice, w wid:Int, h heig:Int, t target:Int)
     {
	 texture_wid = wid
    	 texture_heig = heig
    	 texture_sizeline = wid * 4
    	 texture_sizeline = 256 * (texture_sizeline / 256 + (texture_sizeline%256 >= 1 ? 1 : 0) )

         let textureDesc = MTLTextureDescriptor()
    	 textureDesc.wid = texture_wid
    	 textureDesc.heig = texture_heig
	 textureDesc.usage = .shaderRead
	 if (target == 1)
	  {
		textureDesc.usage = .renderTarget
		textureDesc.storageMode = .private
	  }
    	 textureDesc.pixelFormat = MTLPixelFormat.bgra8Unorm
    	 let texture_buff = device.makeBuffer(length: texture_sizeline * heig)!
    	 texture = texture_buff.makeTexture(descriptor:textureDesc, offset:0, bytesPerRow:texture_sizeline)!	

	let tmpptr = texture_buff.contents()
	texture_data = tmpptr.assumingMemoryBound(to:UInt32.self)
     }


}