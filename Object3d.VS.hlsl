//float4 main( float4 pos : POSITION ) : SV_POSITION
//{

//struct VertexShaderOutput
//{
//    float32_t4 position : SV_POSITION;
//};
	
//struct Vertex

	
	
	
//	return pos;
//}
struct VertexShaderOutput
{
    float32_t4 position : SV_POSITION;
};
    struct VertexShaderInput
    {
        float32_t4 position : POSITION0;
    };
    VertexShaderOutput main(VertexShaderInput input)
    {
        VertexShaderOutput output;
    output.position=input.position;
        return output;
    }

struct TransformationMatrix
{
    float32_t4x4 WVP;
};
ConstantBuffer<TransformationMatrix> gTransformationMatrix : register(b0);
struct VertexShaderOutput{
    float32_t4 position : SV_POSITION;
};
//struct VertexShaderInput
//{
//    float32_t4 position : POSITIONO;
//};
VertexShaderInput main(VertexShaderInput input)
{
    VertexShaderOutput output;
    output.position = mul(input.position, gTransformationMatrix.WVP);
    return output;
}