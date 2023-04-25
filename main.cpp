#include <Novice.h>
#include<math.h>
const char kWindowTitle[] = "GC2D_11_ゾヨンファン";
struct Vector3
{
	float x;
	float y;
	float z;
};
struct result
{
	float  v[2][1];
};
//加算
Vector3 add(Vector3 v1, Vector3 v2) {
	Vector3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}
//減算
Vector3 subtract(Vector3 v1, Vector3 v2) {
	Vector3 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}
//スカラー倍
Vector3 multiply(float k, const Vector3 v1) {
	Vector3 result;
	result.x = k * v1.x;
	result.y = k * v1.y;
	result.z = k * v1.z;

	return result;
};
//内積
float Dot(const Vector3& v1, const Vector3& v2) {
	float result;
	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return result;
}
//長さ
float Length(const Vector3& v) {
	float result;
	result = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return result;
}
//正規化
Vector3 Normalize(const Vector3& v) {
	Vector3 result;
	result.x = v.x / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	result.y = v.y / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	result.z = v.z / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return result;
}
static const int kRowHeight = 20;
static const int kColumnWidth = 60;

void VectorScreenPrintf(int x, int y, const Vector3 vector, const char* label)
{
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 v1;
	v1.x = 1.0f;
	v1.y = 3.0f;
	v1.z = -5.0f;
	Vector3 v2;
	v2.x = 4.0f;
	v2.y = -1.0f;
	v2.z = 2.0f;
	float k = { 4.0f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから

		Vector3 resultAdd = add(v1, v2);
		Vector3 resultSubtract = subtract(v1, v2);
		Vector3 resultMultiply = multiply(k, v1);
		float resultDot = Dot(v1, v2);
		float resultLength = Length(v1);
		Vector3 resultNormalize = Normalize(v2);

		VectorScreenPrintf(0, kRowHeight * 0, resultAdd, " :Add");
		VectorScreenPrintf(0, kRowHeight + 5, resultSubtract, " :Sub");
		VectorScreenPrintf(0, kRowHeight * 2 + 20, resultMultiply, " :Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3 + 20, "%.02f :Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4 + 20, "%.02f :Length", resultLength);
		VectorScreenPrintf(0, kRowHeight * 5 + 20, resultNormalize, " :Normalize");



		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
