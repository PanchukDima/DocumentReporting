#ifndef PAGEMETRICS_H
#define PAGEMETRICS_H

#include <QString>
#include <QSizeF>
#include <QMarginsF>
#include <QPrinter>
#include <QPageSize>

class QPaintDevice;


/**
 * @brief Класс метрик страницы
 */
class PageMetrics
{
public:
	/**
	 * @brief Перевести миллиметры в пикселы
	 * @param _x указывает направление (горизонтальное - true или вертикальное - false), в котором
	 * необходимо произвести рассчёт
	 */
	static qreal mmToPx(qreal _mm, bool _x = true);

	/**
	 * @brief Получить размер страницы из строки
	 */
	static QPageSize::PageSizeId pageSizeIdFromString(const QString& _from);

	/**
	 * @brief Получить строку из размера страницы
	 */
	static QString stringFromPageSizeId(QPageSize::PageSizeId _pageSize);

public:
	PageMetrics(QPageSize::PageSizeId _pageFormat = QPageSize::A4, QMarginsF _mmMargins = QMarginsF());

	/**
	 * @brief Обновить метрики
	 */
    void update(QPageSize::PageSizeId _pageFormat, QMarginsF _mmPageMargins = QMarginsF(), QPrinter::Orientation _orientation = QPrinter::Portrait);

	/**
	 * @brief Методы доступа к параметрам страницы
	 */
	/** @{ */
	QPageSize::PageSizeId pageFormat() const;
	QSizeF mmPageSize() const;
	QMarginsF mmPageMargins() const;
	QSizeF pxPageSize() const;
	QMarginsF pxPageMargins() const;
    QPrinter::Orientation orientation() const;
	/** @} */

private:
	/**
	 * @brief Формат страницы
	 */
	QPageSize::PageSizeId m_pageFormat;

	/**
	 * @brief Размеры в миллиметрах
	 */
	/** @{ */
	QSizeF m_mmPageSize;
	QMarginsF m_mmPageMargins;
	/** @} */

	/**
	 * @brief Размеры в пикселах
	 */
	/** @{ */
	QSizeF m_pxPageSize;
	QMarginsF m_pxPageMargins;
    /**
     * @brief Ориентация страницы
     * @return
     */
    QPrinter::Orientation m_orientation;
	/** @} */

};

#endif // PAGEMETRICS_H
