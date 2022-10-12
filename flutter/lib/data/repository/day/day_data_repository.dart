import '../../api/day/api_util.dart';
import '../../../domain/model/day.dart';
import '../../../domain/repository/day_repository.dart';
import '../../../domain/repository/day_repository.dart';

class DayDataRepository extends DayRepository {
  final ApiUtil _apiUtil;

  DayDataRepository(this._apiUtil);

  @override
  Future<Day> getDay({double latitude, double longitude}) {
    return _apiUtil.getDay(latitude: latitude, longitude: longitude);
  }
}
